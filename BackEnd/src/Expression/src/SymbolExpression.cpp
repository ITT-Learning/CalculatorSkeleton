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

namespace calculator { namespace expression
{
// ---------------------------------------------------------------------------//
// //
// SymbolExpression<T> Public Methods //
// //
// ---------------------------------------------------------------------------//
template<typename T>
SymbolExpression<T>::SymbolExpression(char glyph, bool isPositive): glyph_{glyph}, isPositive_{isPositive}
{
}

template<typename T>
SymbolExpression<T>::~SymbolExpression() = default;

// ---------------------------------------------------------------------------//
// //
// IExpression<T> Public Methods //
// //
// ---------------------------------------------------------------------------//
template<typename T>
boost::optional<T> SymbolExpression<T>::calculateExpression() const
{
    return boost::none;
}

template<typename T>
std::unique_ptr<IExpression<T>> SymbolExpression<T>::bindValueToSymbol(
        char glyph, T value)
{
    std::unique_ptr<IExpression<T>> result{nullptr};
    if(glyph == glyph_)
    {
        if(isPositive_)
        {
            result = std::make_unique<ValueExpression<T>>(value);
        }
        else
        {
            result = std::make_unique<ValueExpression<T>>(-value);
        }
    }
    
    return result;
}

template<typename T>
void SymbolExpression<T>::collectUnboundSymbols(std::set<char> &unboundSymbols) const
{
    unboundSymbols.insert(glyph_);
}

template<typename T>
std::string SymbolExpression<T>::toString() const
{
    std::string result{glyph_};
    if(!isPositive_)
    {
        result = '-' + result;
    }
    return result;
}

template<typename T>
flatbuffer::ExpressionUnion SymbolExpression<T>::toFlatBufferObject() const
{
    flatbuffer::ExpressionUnion result;
    flatbuffer::SymbolExpressionT resultData;
    resultData.symbol = glyph_;
    resultData.isPositive = isPositive_;
    result.Set<flatbuffer::SymbolExpressionT>(std::move(resultData));
    return result;
}

template class SymbolExpression<int>;
template class SymbolExpression<double>;
}}
