////////////////////////////////////////////////////////////////////////////////
/**
 * @file IExpression.cpp
 * @date Tues March 1 2022
 * @brief implementation for an interface that represents a mathematical
 * expression that can have symbols, values, and operators
 */
////////////////////////////////////////////////////////////////////////////////

#include "IExpression.h"

namespace calculator { namespace expression
{
// ---------------------------------------------------------------------------//
// //
// IExpression<T> Public Methods //
// //
// ---------------------------------------------------------------------------//
template<typename T>
IExpression<T>::~IExpression() = default;

template<typename T>
std::string IExpression<T>::toString(const IExpression<T> &expression)
{
    std::string result = expression.toString();
    if(result[0] == '(' && result[result.length() - 1] == ')')
    {
        result = result.substr(1, result.length() - 2);
    }
    return result;
}

template class IExpression<int>;
template class IExpression<double>;
}}
