////////////////////////////////////////////////////////////////////////////////
/**
 * @file ExpressionInterface.cpp
 * @date Tues March 1 2022
 * @brief implementation for an interface that represents a mathematical
 * expression that can have symbols, values, and operators
 */
////////////////////////////////////////////////////////////////////////////////

#include "ExpressionInterface.h"

namespace calculator { namespace expression
{
// ---------------------------------------------------------------------------//
// //
// ExpressionInterface<T> Public Methods //
// //
// ---------------------------------------------------------------------------//
template<typename T>
ExpressionInterface<T>::~ExpressionInterface() = default;

template class ExpressionInterface<int>;
template class ExpressionInterface<double>;
}}
