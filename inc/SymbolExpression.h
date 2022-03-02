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
         */
        SymbolExpression(char glyph);

        virtual ~SymbolExpression();

        boost::optional<T> calculateExpression() const override;
        std::unique_ptr<IExpression<T>> bindValueToSymbol(char glyph,
                T value) override;
        std::string toString() const override;
    private:
        char glyph_;
};
}}

#endif // #ifndef SYMBOLEXPRESSION_H
