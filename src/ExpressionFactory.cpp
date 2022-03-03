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
                result = OperatorType(currentChar);
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

template class ExpressionFactory<int>;
template class ExpressionFactory<double>;
}}
