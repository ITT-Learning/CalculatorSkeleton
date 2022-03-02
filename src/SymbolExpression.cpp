////////////////////////////////////////////////////////////////////////////////
/**
 * @file SymbolExpression.cpp
 * @date Fri February 25 2022
 * @brief implementation for a symbol in a mathematical expression
 */
////////////////////////////////////////////////////////////////////////////////

#include "SymbolExpression.h"

#include <iostream>
#include <memory>

#include "ValueExpression.h"

namespace calculator::expression
{
// ---------------------------------------------------------------------------//
// //
// SymbolExpression<T> Public Methods //
// //
// ---------------------------------------------------------------------------//
template<typename T>
SymbolExpression<T>::SymbolExpression(char glyph): glyph_{glyph}
{
}

template<typename T>
SymbolExpression<T>::~SymbolExpression() = default;

// ---------------------------------------------------------------------------//
// //
// ExpressionInterface<T> Public Methods //
// //
// ---------------------------------------------------------------------------//
template<typename T>
boost::optional<T> SymbolExpression<T>::calculateExpression() const
{
    return boost::none;
}

template<typename T>
std::unique_ptr<ExpressionInterface<T>> SymbolExpression<T>::bindValueToSymbol(
        char glyph, T value)
{
    std::unique_ptr<ExpressionInterface<T>> result{nullptr};
    if(glyph == glyph_)
    {
        result = std::make_unique<ValueExpression<T>>(value);
    }
    return result;
}

template<typename T>
std::string SymbolExpression<T>::toString() const
{
    return std::string{glyph_};
}

template class SymbolExpression<int>;
template class SymbolExpression<double>;
}
