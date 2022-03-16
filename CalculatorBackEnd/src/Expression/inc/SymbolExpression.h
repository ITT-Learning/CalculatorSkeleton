////////////////////////////////////////////////////////////////////////////////
/**
 * @file SymbolExpression.h
 * @date Fri February 25 2022
 * @brief header for a symbol in a mathematical expression
 */
////////////////////////////////////////////////////////////////////////////////

#ifndef SYMBOLEXPRESSION_H
#define SYMBOLEXPRESSION_H

#include <set>

#include <boost/optional.hpp>

#include "IExpression.h"

namespace calculator { namespace expression
{
/**
 * @brief a class representing a symbol in a mathematical expression
 * @tparam T the type of numbers involved in this expression (int or double,
 * for example)
 */
template<typename T>
class SymbolExpression : public IExpression<T>
{
    public:
        /**
         * @brief Construct a new SymbolExpression object with the given glyph
         * @param [in] glyph the glyph (written character) to represent this
         * symbol
         * @param [in] isPositive whether the glyph is positive or negative
         */
        SymbolExpression(char glyph, bool isPositive);

        virtual ~SymbolExpression();

        boost::optional<T> calculateExpression() const override;
        std::unique_ptr<IExpression<T>> bindValueToSymbol(char glyph,
                T value) override;
        void collectUnboundSymbols(std::set<char> &unboundSymbols) const override;
        std::string toString() const override;
        flatbuffer::ExpressionUnion toFlatBufferObject() const override;
    private:
        char glyph_;
        bool isPositive_;
};
}}

#endif // #ifndef SYMBOLEXPRESSION_H
