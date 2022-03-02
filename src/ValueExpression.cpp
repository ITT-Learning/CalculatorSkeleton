////////////////////////////////////////////////////////////////////////////////
/**
 * @file ValueExpression.cpp
 * @date Fri February 25 2022
 * @brief implementation for a numerical value in a mathematical expression
 */
////////////////////////////////////////////////////////////////////////////////

#include "ValueExpression.h"

namespace calculator::expression
{
// ---------------------------------------------------------------------------//
// //
// ValueExpression<T> Public Methods //
// //
// ---------------------------------------------------------------------------//
template<typename T>
ValueExpression<T>::ValueExpression(T value): value_{value}
{
}

template<typename T>
ValueExpression<T>::~ValueExpression() = default;

// ---------------------------------------------------------------------------//
// //
// ExpressionInterface<T> Public Methods //
// //
// ---------------------------------------------------------------------------//
template<typename T>
boost::optional<T> ValueExpression<T>::calculateExpression() const
{
    return value_;
}

template<typename T>
std::unique_ptr<ExpressionInterface<T>> ValueExpression<T>::bindValueToSymbol(
        char glyph, T value)
{
    return nullptr;
}

template<>
std::string ValueExpression<int>::toString() const
{
    // don't use a generic form here because std::to_string() might not exist
    // for an arbitrary type T
    return std::to_string(value_);
}

template<>
std::string ValueExpression<double>::toString() const
{
    // don't use a generic form here because std::to_string() might not exist
    // for an arbitrary type T
    return std::to_string(value_);
}

template class ValueExpression<int>;
template class ValueExpression<double>;
}
