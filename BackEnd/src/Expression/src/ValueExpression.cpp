////////////////////////////////////////////////////////////////////////////////
/**
 * @file ValueExpression.cpp
 * @date Fri February 25 2022
 * @brief implementation for a numerical value in a mathematical expression
 */
////////////////////////////////////////////////////////////////////////////////

#include "ValueExpression.h"

namespace calculator { namespace expression
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
// IExpression<T> Public Methods //
// //
// ---------------------------------------------------------------------------//
template<typename T>
boost::optional<T> ValueExpression<T>::calculateExpression() const
{
    return value_;
}

template<typename T>
std::unique_ptr<IExpression<T>> ValueExpression<T>::bindValueToSymbol(
        char glyph, T value)
{
    return nullptr;
}

template<typename T>
void ValueExpression<T>::collectUnboundSymbols(std::set<char> &unboundSymbols) const
{
    return;
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

template<>
flatbuffer::ExpressionUnion ValueExpression<int>::toFlatBufferObject() const
{
    flatbuffer::ExpressionUnion result;
    flatbuffer::IntValueExpressionT resultData;
    resultData.value = value_;
    result.Set<flatbuffer::IntValueExpressionT>(std::move(resultData));
    return result;
}

template<>
flatbuffer::ExpressionUnion ValueExpression<double>::toFlatBufferObject() const
{
    flatbuffer::ExpressionUnion result;
    flatbuffer::DoubleValueExpressionT resultData;
    resultData.value = value_;
    result.Set<flatbuffer::DoubleValueExpressionT>(std::move(resultData));
    return result;
}

template class ValueExpression<int>;
template class ValueExpression<double>;
}}
