////////////////////////////////////////////////////////////////////////////////
/**
 * @file ExpressionFactory.cpp
 * @date Tues March 1 2022
 * @brief implementation for a class with various static methods that can build
 * an expression tree
 */
////////////////////////////////////////////////////////////////////////////////

#include "ExpressionFactory.h"

#include <cctype>
#include <iostream>
#include <regex>
#include <set>
#include <string>
#include <string_view>
#include <thread>

#include <boost/algorithm/string.hpp>
#include <boost/utility/string_ref.hpp>

#include "OperatorExpression.h"
#include "SymbolExpression.h"
#include "ValueExpression.h"

namespace calculator { namespace expression
{
// ---------------------------------------------------------------------------//
// //
// ExpressionFactory<T> Public Methods //
// //
// ---------------------------------------------------------------------------//
template<typename T>
std::unique_ptr<IExpression<T>> ExpressionFactory<T>::
        parseFromSingleOperationString(const std::string &string)
{
    std::unique_ptr<IExpression<T>> result{nullptr};
    std::stringstream stream{string};
    T leftValue;
    if(stream >> leftValue)
    {
        std::unique_ptr<ValueExpression<T>> leftExpression = 
                std::make_unique<ValueExpression<T>>(leftValue);
        auto operatorType = consumeOperatorFromStream(stream);
        if(operatorType)
        {
            T rightValue;
            if(stream >> rightValue && stream.get() == std::char_traits<char>::eof())
            {
                // successfully parsed all pieces, and there's nothing else in the stream
                std::unique_ptr<ValueExpression<T>> rightExpression = 
                        std::make_unique<ValueExpression<T>>(rightValue);
                result = std::make_unique<OperatorExpression<T>>(
                        std::move(leftExpression),
                        std::move(rightExpression),
                        *operatorType);
            }
        }
    }
    
    return result;
}

template<typename T>
std::unique_ptr<IExpression<T>> ExpressionFactory<T>::parseFromComplexString(
        const std::string &complexString)
{
    return parseFromComplexStringInternal(complexString);
}

// ---------------------------------------------------------------------------//
// //
// ExpressionFactory<T> Private Methods //
// //
// ---------------------------------------------------------------------------//
template<typename T>
ExpressionFactory<T>::ExpressionFactory() = default;

template<typename T>
boost::optional<T> ExpressionFactory<T>::consumeValueFromStream(
        std::istream &stream)
{
    boost::optional<T> result{boost::none};
    T val;
    if(stream >> val)
    {
        result = val;
    }
    
    return result;
}

template<typename T>
boost::optional<OperatorType> ExpressionFactory<T>::
        consumeOperatorFromStream(std::istream &stream)
{
    boost::optional<OperatorType> result{boost::none};
    bool searching{true};
    while(searching)
    {
        int currentChar = stream.get();
        // since only one case continues the search (when we see a whitespace char), and all other cases stop the
        // search, just set searching = false here to save some lines of code
        searching = false;
        switch(currentChar)
        {
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
                result = static_cast<OperatorType>(currentChar);
                break;
            case ' ':
            case '\t':
            case '\n':
            case '\v':
            case '\f':
            case '\r':
                // whitespace
                searching = true;
                break;
            case std::char_traits<char>::eof():
                // end of stream
                break;
            default:
                // we encountered a non-whitespace, non-operator character, so put it back in the stream to make sure 
                // the stream doesn't get messed up
                stream.putback(currentChar);
                break;
        }
    }
    
    return result;
}

template<typename T>
boost::optional<std::pair<bool, char>> ExpressionFactory<T>::consumeSymbolFromStream(std::istream &streamFromWhichToConsume)
{
    boost::optional<std::pair<bool, char>> result{boost::none};
    bool searching{true};
    bool isPositive{true};
    while(searching)
    {
        int currentChar = streamFromWhichToConsume.get();
        // since only one case continues the search (when we see a whitespace char), and all other cases stop the
        // search, just set searching = false here to save some lines of code
        searching = false;
        if(currentChar == '-' && isPositive)
        {
            if(isPositive)
            {
                isPositive = false;
                searching = true;
            }
            // if not, we already saw a negative sign, and we're not going to allow multiple negative signs to be
            // applied to the same symbol
        }
        else if(std::isalpha(currentChar))
        {
            result = std::pair<bool, char>(isPositive, static_cast<char>(currentChar));
        }
        else if(std::isspace(currentChar))
        {
            searching = true;
        }
        else if(currentChar != std::char_traits<char>::eof())
        {
            streamFromWhichToConsume.putback(currentChar);
        }
    }

    return result;
}

template<typename T>
std::unique_ptr<IExpression<T>> ExpressionFactory<T>::parseFromComplexStringInternal(
        boost::string_ref stringSlice)
{
    std::unique_ptr<IExpression<T>> result{nullptr};
    trimUnneededCharacters(stringSlice);
    auto nextOperator = findNextOperator(stringSlice);
    if(nextOperator != boost::none)
    {
        std::unique_ptr<IExpression<T>> leftExpr{nullptr};
        std::unique_ptr<IExpression<T>> rightExpr{nullptr};
        // Threading here *won't* cause any issues because the main thread
        // blocks until all sub-threads are finished with their parsing, and
        // neither parseFromComplexStringInternal() nor any of the functions
        // that it calls modifies the string underlying the stringSlice
        std::thread leftThread{[&](){
            leftExpr = parseFromComplexStringInternal(stringSlice.substr(0, nextOperator->first));
        }};
        std::thread rightThread{[&](){
            rightExpr = parseFromComplexStringInternal(stringSlice.substr(nextOperator->first + 1,
                stringSlice.length() - nextOperator->first - 1));
        }};
        leftThread.join();
        rightThread.join();
        if(leftExpr != nullptr && rightExpr != nullptr)
        {
            result = std::make_unique<OperatorExpression<T>>(std::move(leftExpr), std::move(rightExpr),
                    nextOperator->second);
        }
    }
    else
    {
        // No operator found. See if it's a simple expression.
        result = parseSimpleExpression(stringSlice);
    }
    return result;
}

template<typename T>
bool ExpressionFactory<T>::trimUnneededCharacters(boost::string_ref &toTrim)
{
    bool result = false;
    bool changedLastIteration = true;
    while(changedLastIteration)
    {
        changedLastIteration = trimWhiteSpace(toTrim) || trimEnclosingParentheses(toTrim);
        result = result || changedLastIteration;
    }
    return result;
}

template<typename T>
bool ExpressionFactory<T>::trimWhiteSpace(boost::string_ref &toTrim)
{
    return trimLeadingWhiteSpace(toTrim) || trimTrailingWhiteSpace(toTrim);
}

template<typename T>
bool ExpressionFactory<T>::trimLeadingWhiteSpace(boost::string_ref &toTrim)
{
    bool result = false;
    std::size_t i = 0;
    for(i = 0; i < toTrim.length(); i++)
    {
        if(!isspace(toTrim[i]))
        {
            break;
        }
    }
    if(i != 0)
    {
        // some white space
        result = true;
        if(toTrim.length() == i)
        {
            toTrim = toTrim.substr(0, 0);
            // entire string is white space. just return the empty string.
        }
        else
        {
            toTrim = toTrim.substr(i, toTrim.length() - i);
        }
    }
    return result;
}

template<typename T>
bool ExpressionFactory<T>::trimTrailingWhiteSpace(boost::string_ref &toTrim)
{
    bool result = false;
    std::size_t i = toTrim.length();
    for(i = toTrim.length(); i > 0; i--)
    {
        if(!isspace(toTrim[i - 1]))
        {
            break;
        }
    }
    if(i != toTrim.length())
    {
        // some white space
        result = true;
        if(0 == i)
        {
            toTrim = toTrim.substr(0, 0);
            // entire string is white space. just return the empty string.
        }
        else
        {
            toTrim = toTrim.substr(0, i);
        }
    }
    return result;
}

template<typename T>
bool ExpressionFactory<T>::trimEnclosingParentheses(boost::string_ref &toTrim)
{
    bool result = false;
    while(toTrim.length() >= 2)
    {
        if('(' == toTrim[0] && ')' == toTrim[toTrim.length() - 1])
        {
            toTrim = toTrim.substr(1, toTrim.length() - 2);
            result = true;
        }
        else
        {
            // no more parentheses pairs
            break;
        }
    }
    return result;
}

template<typename T>
boost::optional<std::pair<std::size_t, OperatorType>> ExpressionFactory<T>::findNextOperator(const boost::string_ref &stringSlice)
{
    boost::optional<std::pair<std::size_t, OperatorType>> result = boost::none;
    boost::optional<std::pair<std::size_t, OperatorType>> firstAddSubtract = boost::none;
    boost::optional<std::pair<std::size_t, OperatorType>> firstMultiplyDivide = boost::none;
    int parenthesisDepth = 0;
    // I don't like the guard here because it essentially checks for overflow. Maybe make i signed. TODO
    for(std::size_t i = stringSlice.length() - 1; i < stringSlice.length(); i--)
    {
        // basically we have to go backwards as we're building up the tree. addition/subtraction get parsed first
        // because they have the lowest precedence, and the last operator with the lowest precedence gets parsed first
        switch(stringSlice[i])
        {
            case '(':
                parenthesisDepth--;
                break;
            case ')':
                parenthesisDepth++;
                break;
            case static_cast<char>(OperatorType::SUBTRACTION):
                if(!minusIsOperator(stringSlice, i))
                {
                    break;
                }
                // fall through if the minus is actually an operator
            case static_cast<char>(OperatorType::ADDITION):
                if(boost::none == firstAddSubtract && 0 == parenthesisDepth)
                {
                    firstAddSubtract = boost::optional<std::pair<std::size_t, OperatorType>>({i,
                            static_cast<OperatorType>(stringSlice[i])});
                    // we could break out here, but not without goto because we're nested too deep, and the coding
                    // standards strongly discourage goto
                }
                break;
            case static_cast<char>(OperatorType::MULTIPLICATION):
            case static_cast<char>(OperatorType::DIVISION):
            case static_cast<char>(OperatorType::MODULO):
                if(boost::none == firstMultiplyDivide && 0 == parenthesisDepth)
                {
                    firstMultiplyDivide = boost::optional<std::pair<std::size_t, OperatorType>>({i, static_cast<OperatorType>(stringSlice[i])});
                }
                break;
        }
        // some early end conditions
        if(parenthesisDepth < 0)
        {
            // Something bad happened. The user entered a string that has a closing parenthesis without a matching
            // opening parenthesis
            firstAddSubtract = boost::none;
            firstMultiplyDivide = boost::none;
            break;
        }
        else if(firstAddSubtract != boost::none)
        {
            break;
        }
    }
    result = firstMultiplyDivide;
    if(firstAddSubtract != boost::none)
    {
        result = firstAddSubtract;
    }
    return result;
}

template<typename T>
std::unique_ptr<IExpression<T>> ExpressionFactory<T>::parseSimpleExpression(const boost::string_ref &stringSlice)
{
    std::unique_ptr<IExpression<T>> result{nullptr};
    // TODO this string conversion is kinda costly. Maybe we should refactor these methods to take string_refs instead
    // of stringstreams
    const std::string stringToScan = stringSlice.to_string();
    std::stringstream streamFromWhichToConsume{stringToScan};
    auto possibleValue = consumeValueFromStream(streamFromWhichToConsume);
    if(boost::none != possibleValue)
    {
        if(std::char_traits<char>::eof() == streamFromWhichToConsume.peek())
        {
            result = std::make_unique<ValueExpression<T>>(*possibleValue);
        }
    }
    else
    {
        streamFromWhichToConsume = std::stringstream{stringToScan};
        auto possibleSymbol = consumeSymbolFromStream(streamFromWhichToConsume);
        if(boost::none != possibleSymbol)
        {
            if(std::char_traits<char>::eof() == streamFromWhichToConsume.peek())
            {
                result = std::make_unique<SymbolExpression<T>>(possibleSymbol->second, possibleSymbol->first);
            }
        }
    }

    return result;
}

template<typename T>
bool ExpressionFactory<T>::minusIsOperator(const boost::string_ref &expressionString, std::size_t minusPosition)
{
    bool result = true;
    if(0 == minusPosition)
    {
        result = false;
    }
    else
    {
        // look backwards and see if the previous token was an operator
        for(std::size_t i = minusPosition - 1; i >= 0; i--)
        {
            if(!isspace(expressionString[i]))
            {
                switch(expressionString[i])
                {
                    case static_cast<char>(OperatorType::SUBTRACTION):
                    case static_cast<char>(OperatorType::ADDITION):
                    case static_cast<char>(OperatorType::MULTIPLICATION):
                    case static_cast<char>(OperatorType::DIVISION):
                    case static_cast<char>(OperatorType::MODULO):
                        result = false;
                        break;
                }
                // break out of the loop, since the loop is only to traverse the white space
                break;
            }
        }
    }
    return result;
}

template class ExpressionFactory<int>;
template class ExpressionFactory<double>;
}}
