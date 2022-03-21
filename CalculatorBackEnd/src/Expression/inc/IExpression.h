////////////////////////////////////////////////////////////////////////////////
/**
 * @file IExpression.h
 * @date Fri February 25 2022
 * @brief header for an interface that represents a mathematical expression that
 * can have symbols, values, and operators
 */
////////////////////////////////////////////////////////////////////////////////

#ifndef IEXPRESSION_H
#define IEXPRESSION_H

#include <memory>
#include <set>
#include <string>

#include <boost/optional.hpp>
#include <flatbuffers/flatbuffers.h>

#include "Expression_generated.h"

namespace calculator { namespace expression
{
/**
 * @brief an abstract interface containing all methods that a mathematical
 * expression should support
 * @tparam T the type of numbers involved in this expression (int or double,
 * for example)
 */
template<typename T>
class IExpression
{
    public:
        virtual ~IExpression();

        /**
         * @brief attempts to calculate the value for the whole expression tree,
         * but will not be successful if there are still unbound variables
         * @return boost::optional<T> the value of the expression tree if it
         * could be calculated
         */
        virtual boost::optional<T> calculateExpression() const = 0;

        /**
         * @brief traverses the expression tree, replacing any symbols matching
         * the given glyph with the given value
         * @param [in] glyph the glyph to search and replace
         * @param [in] value the value with which to replace the symbol
         * @return std::unique_ptr<IExpression<T>> a ValueExpression
         * if the node upon which this method was called was a SymbolExpression,
         * otherwise nullptr
         */
        virtual std::unique_ptr<IExpression<T>> bindValueToSymbol(
                char glyph,
                T value) = 0;

        /**
         * @brief collects all unbound symbols in the expression rooted at this node, storing them in the given set
         * @param [out] unboundSymbols the set in which to store all unbound symbols
         */
        virtual void collectUnboundSymbols(std::set<char> &unboundSymbols) const = 0;

        /**
         * @brief converts the expression tree rooted at this node to a human-
         *readable string
         * @return std::string the string representation for the expression tree 
         */
        virtual std::string toString() const = 0;

        /**
         * @brief prepares for serialization by writing this node's data and the data of all child nodes to the given
         * builder
         * @return flatbuffer::ExpressionUnion the flat buffer object representing this expression
         */
        virtual flatbuffer::ExpressionUnion toFlatBufferObject() const = 0;

        /**
         * @brief helper to convert expressions to strings that will also remove opening and closing parentheses in the
         * case of the root expression being an operator
         * @param [in] expression expression from which to convert
         * @return std::string string conversion
         */
        static std::string toString(const IExpression<T> &expression);
};
}}

#endif // #ifndef IEXPRESSION_H
