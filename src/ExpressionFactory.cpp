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
#include <string>

#include "ValueExpression.h"

namespace calculator::expression
{
// ---------------------------------------------------------------------------//
// //
// ExpressionFactory<T> Public Methods //
// //
// ---------------------------------------------------------------------------//
template<typename T>
std::unique_ptr<ExpressionInterface<T>> ExpressionFactory<T>::
        parseFromSingleOperationString(const std::string &string)
{
    std::unique_ptr<ExpressionInterface<T>> result{nullptr};
    std::stringstream stream{string};
    T leftValue;
    if(stream >> leftValue)
    {
        // success on first number
        std::unique_ptr<ValueExpression<T>> leftExpression = 
                std::make_unique<ValueExpression<T>>(leftValue);
        auto operatorType = consumeOperatorFromStream(stream);
        if(operatorType)
        {
            // success on operator
            T rightValue;
            if(stream >> rightValue && stream.get() == std::char_traits<char>::eof())
            {
                // success on second number and nothing else in the stream
                std::unique_ptr<ValueExpression<T>> rightExpression = 
                        std::make_unique<ValueExpression<T>>(rightValue);
                result = std::make_unique<OperatorExpression<T>>(
                        // transfer ownership to result
                        std::move(leftExpression),
                        std::move(rightExpression),
                        *operatorType);
            }
        }
    }
    // copy elision, so this is a move
    return result;
}

// ---------------------------------------------------------------------------//
// //
// ExpressionFactory<T> Private Methods //
// //
// ---------------------------------------------------------------------------//
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
        // we have to peek here (and get the char out later) to make sure that 
        // we don't remove a non-whitespace, non-operator from the stream.
        int currentChar = stream.peek();
        if(currentChar == '+')
        {
            result = OperatorType::ADDITION;
            searching = false;
            stream.get();
        }
        else if(currentChar == '-')
        {
            result = OperatorType::SUBTRACTION;
            searching = false;
            stream.get();
        }
        else if(currentChar == '*')
        {
            result = OperatorType::MULTIPLICATION;
            searching = false;
            stream.get();
        }
        else if(currentChar == '/')
        {
            result = OperatorType::DIVISION;
            searching = false;
            stream.get();
        }
        else if(currentChar == '%')
        {
            result = OperatorType::MODULO;
            searching = false;
            stream.get();
        }
        else if(!isspace(currentChar))
        {
            // we found a non-whitespace character, so we should bail out early
            // but leave that char in the stream, or else we mangle the stream.
            // In the case the stream is EOF, this *should* handle it gracefully
            // as well.
            searching = false;
        }
        else
        {
            // whitespace character, keep consuming until we get to the real
            // stuff
            stream.get();
        }
    }
    return result;
}

template class ExpressionFactory<int>;
template class ExpressionFactory<double>;
}
