////////////////////////////////////////////////////////////////////////////////
/**
 * @file SymbolExpression.h
 * @date Fri February 25 2022
 * @brief header for a symbol in a mathematical expression
 */
////////////////////////////////////////////////////////////////////////////////

#ifndef SYMBOLEXPRESSION_H
#define SYMBOLEXPRESSION_H

#include <boost/optional.hpp>

#include "ExpressionInterface.h"

namespace calculator::expression
{
/**
 * @brief a class representing a symbol in a mathematical expression
 * @tparam T the type of numbers involved in this expression (int or double,
 * for example)
 */
template<typename T>
class SymbolExpression : public ExpressionInterface<T>
{
    public:
        /**
         * @brief Construct a new SymbolExpression object with the given glyph
         * @param glyph the glyph (written character) to represent this symbol
         */
        SymbolExpression(char glyph);

        virtual ~SymbolExpression();

        boost::optional<T> calculateExpression() const override;
        std::unique_ptr<ExpressionInterface<T>> bindValueToSymbol(char glyph,
                T value) override;
        std::string toString() const override;
    private:
        char glyph_;
};
}

#endif // #ifndef SYMBOLEXPRESSION_H