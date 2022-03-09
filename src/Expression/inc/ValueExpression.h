////////////////////////////////////////////////////////////////////////////////
/**
 * @file ValueExpression.h
 * @date Fri February 25 2022
 * @brief header for a numerical value in a mathematical expression
 */
////////////////////////////////////////////////////////////////////////////////

#ifndef VALUEEXPRESSION_H
#define VALUEEXPRESSION_H

#include <set>

#include <boost/optional.hpp>

#include "IExpression.h"

namespace calculator { namespace expression
{
/**
 * @brief a class representing a numerical value in a mathematical expression
 * @tparam T the type of numbers involved in this expression (int or double,
 * for example)
 */
template<typename T>
class ValueExpression: public IExpression<T>
{
    public:
        /**
         * @brief Construct a new ValueExpression object from the given number
         * @param [in] value the number given to this ValueExpression object
         */
        ValueExpression(T value);

        virtual ~ValueExpression();

        boost::optional<T> calculateExpression() const override;
        std::unique_ptr<IExpression<T>> bindValueToSymbol(char glyph,
                T value) override;
        void collectUnboundSymbols(std::set<char> &unboundSymbols) const override;
        std::string toString() const override;
        flatbuffer::ExpressionUnion toFlatBufferObject() const override;
    private:
        const T value_;
};
}}

#endif // #ifndef VALUEEXPRESSION_H
