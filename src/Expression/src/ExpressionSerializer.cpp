#include "ExpressionSerializer.h"

#include "OperatorExpression.h"
#include "SymbolExpression.h"
#include "ValueExpression.h"

namespace calculator { namespace expression
{
// ---------------------------------------------------------------------------//
// //
// ExpressionSerializer<T> Public Methods //
// //
// ---------------------------------------------------------------------------//
template<typename T>
typename ExpressionSerializer<T>::ExpressionBuffer ExpressionSerializer<T>::serialize(const IExpression<T> &expressionTree)
{
    flatbuffers::FlatBufferBuilder builder;
    flatbuffer::ExpressionTreeT treeObject;
    auto rootExpressionObject = expressionTree.toFlatBufferObject();
    treeObject.numberType = numberType_;
    treeObject.expression = rootExpressionObject;
    builder.Finish(flatbuffer::ExpressionTree::Pack(builder, &treeObject));
    return std::vector<uint8_t>{builder.GetBufferPointer(), builder.GetBufferPointer() + builder.GetSize()};
}

template<typename T>
std::unique_ptr<IExpression<T>> ExpressionSerializer<T>::deserialize(const typename ExpressionSerializer<T>::ExpressionBuffer &expressionBuffer)
{
    std::unique_ptr<IExpression<T>> result{nullptr};
    flatbuffer::ExpressionTreeT expressionTree;
    flatbuffer::GetExpressionTree(expressionBuffer.data())->UnPackTo(&expressionTree);
    if(expressionTree.numberType == numberType_)
    {
        result = deserializeInternal(expressionTree.expression);
    }
    return result;
}

// ---------------------------------------------------------------------------//
// //
// ExpressionSerializer<T> Private Methods //
// //
// ---------------------------------------------------------------------------//
template<>
std::unique_ptr<IExpression<int>> ExpressionSerializer<int>::deserializeIntValueExpression(const flatbuffer::IntValueExpressionT &expression)
{
    return std::make_unique<ValueExpression<int>>(expression.value);
}

template<>
std::unique_ptr<IExpression<double>> ExpressionSerializer<double>::deserializeIntValueExpression(const flatbuffer::IntValueExpressionT &expression)
{
    return nullptr;
}

template<>
std::unique_ptr<IExpression<int>> ExpressionSerializer<int>::deserializeDoubleValueExpression(const flatbuffer::DoubleValueExpressionT &expression)
{
    return nullptr;
}

template<>
std::unique_ptr<IExpression<double>> ExpressionSerializer<double>::deserializeDoubleValueExpression(const flatbuffer::DoubleValueExpressionT &expression)
{
    return std::make_unique<ValueExpression<double>>(expression.value);
}

template<>
const flatbuffer::NumberType ExpressionSerializer<int>::numberType_ = flatbuffer::NumberType_INTEGER;

template<>
const flatbuffer::NumberType ExpressionSerializer<double>::numberType_ = flatbuffer::NumberType_DOUBLE;

template<typename T>
std::unique_ptr<IExpression<T>> ExpressionSerializer<T>::deserializeInternal(const flatbuffer::ExpressionUnion &expression)
{
    std::unique_ptr<IExpression<T>> result{nullptr};
    switch(expression.type)
    {
        case flatbuffer::Expression_OperatorExpression:
            result = deserializeOperatorExpression(*expression.AsOperatorExpression());
            break;
        case flatbuffer::Expression_SymbolExpression:
            result = deserializeSymbolExpression(*expression.AsSymbolExpression());
            break;
        case flatbuffer::Expression_IntValueExpression:
            result = deserializeIntValueExpression(*expression.AsIntValueExpression());
            break;
        case flatbuffer::Expression_DoubleValueExpression:
            result = deserializeDoubleValueExpression(*expression.AsDoubleValueExpression());
            break;
    }
    return result;
}

template<typename T>
std::unique_ptr<IExpression<T>> ExpressionSerializer<T>::deserializeOperatorExpression(const flatbuffer::OperatorExpressionT &expression)
{
    auto left = deserializeInternal(expression.left);
    auto right = deserializeInternal(expression.right);
    return std::make_unique<OperatorExpression<T>>(std::move(left), std::move(right), static_cast<OperatorType>(expression.operator_));
}

template<typename T>
std::unique_ptr<IExpression<T>> ExpressionSerializer<T>::deserializeSymbolExpression(const flatbuffer::SymbolExpressionT &expression)
{
    return std::make_unique<SymbolExpression<T>>(expression.symbol, expression.isPositive);
}

template class ExpressionSerializer<int>;
template class ExpressionSerializer<double>;
}}

