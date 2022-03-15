////////////////////////////////////////////////////////////////////////////////
/**
 * @file ExpressionSerializer.h
 * @date Thu March 10 2022
 * @brief header for a class with static methods to serialize and deserialize expressions to and from flatbuffers
 */
////////////////////////////////////////////////////////////////////////////////
#ifndef EXPRESSIONSERIALIZER_H
#define EXPRESSIONSERIALIZER_H

#include <memory>

#include "Expression_generated.h"
#include "IExpression.h"

namespace calculator { namespace expression
{

/**
 * @brief a class with static methods to serialize and deserialize expressions to and from flatbuffers
 * @tparam T the type of numbers involved in the expressions to be serialized and/or deserialized
 */
template<typename T>
class ExpressionSerializer
{
    public:
        using ExpressionBuffer = std::vector<uint8_t>;

        /**
         * @brief serializes the given expression tree into a flatbuffer
         * @param [in] expressionTree the expression tree to serialize
         * @return std::vector<uint8_t> The raw serialized bytes representing the expression tree
         */
        static ExpressionBuffer serialize(const IExpression<T> &expressionTree);

        /**
         * @brief deserializes the given buffer, assuming that it represents an ExpressionTree flatbuffer, producing an
         * IExpression<T> tree
         * @param [in] expressionBuffer the buffer to parse
         * @return std::unique_ptr<IExpression<T>> the expression tree produced
         */
        static std::unique_ptr<IExpression<T>> deserialize(const ExpressionBuffer &expressionBuffer);
    private:
        ExpressionSerializer();

        /**
         * @brief deserializes the given ExpressionUnion flatbuffer object, producing an IExpression<T> tree
         * @param expression the expression flatbuffer object to parse
         * @return std::unique_ptr<IExpression<T>> the expression tree produced
         */
        static std::unique_ptr<IExpression<T>> deserializeInternal(const flatbuffer::ExpressionUnion &expression);

        /**
         * @brief deserializes the given OperatorExpression flatbuffer, producing an IExpression<T> tree
         * @param [in] expression the OperatorExpression flatbuffer to parse
         * @return std::unique_ptr<IExpression<T>> the expression tree produced
         */
        static std::unique_ptr<IExpression<T>> deserializeOperatorExpression(const flatbuffer::OperatorExpressionT &expression);

        /**
         * @brief deserializes the given SymbolExpression flatbuffer, producing an IExpression<T> tree
         * @param [in] expression the SymbolExpression flatbuffer to parse
         * @return std::unique_ptr<IExpression<T>> the expression tree produced
         */
        static std::unique_ptr<IExpression<T>> deserializeSymbolExpression(const flatbuffer::SymbolExpressionT &expression);

        /**
         * @brief deserializes the given IntValue flatbuffer, producing an IExpression<T> tree
         * @param [in] expression the IntValue flatbuffer to parse
         * @return std::unique_ptr<IExpression<T>> the expression tree produced
         */
        static std::unique_ptr<IExpression<T>> deserializeIntValueExpression(const flatbuffer::IntValueExpressionT &expression);

        /**
         * @brief deserializes the given DoubleValue flatbuffer, producing an IExpression<T> tree
         * @param [in] expression the DoubleValue flatbuffer to parse
         * @return std::unique_ptr<IExpression<T>> the expression tree produced
         */
        static std::unique_ptr<IExpression<T>> deserializeDoubleValueExpression(const flatbuffer::DoubleValueExpressionT &expression);

        static const flatbuffer::NumberType numberType_;
};

}}

#endif // #ifndef EXPRESSIONSERIALIZER_H