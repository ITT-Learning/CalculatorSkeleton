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

template class IExpression<int>;
template class IExpression<double>;
}}
