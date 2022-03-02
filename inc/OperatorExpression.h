////////////////////////////////////////////////////////////////////////////////
/**
 * @file OperatorExpression.h
 * @date Fri February 25 2022
 * @brief header for a mathematical operator acting on two sub-expressions
 */
////////////////////////////////////////////////////////////////////////////////

#ifndef OPERATOREXPRESSION_H
#define OPERATOREXPRESSION_H

#include <memory>

#include "ExpressionInterface.h"

namespace calculator { namespace expression
{
/**
 * @brief a type of mathematical binary operator
 */
enum class OperatorType
{
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION,
    MODULO
};

/**
 * @brief a class representing a mathematical operator acting on two
 * sub-expressions
 * @tparam T the type of numbers involved in this expression (int or double,
 * for example)
 */
template<typename T>
class OperatorExpression : public ExpressionInterface<T>
{
    public:
        /**
         * @brief Construct a new OperatorExpression object from the given left
         * and right sub-expressions and the given operator
         * @param [in] left the left sub-expression of which this
         * OperatorExpression will take ownership
         * @param [in] right the right sub-expression of which this
         * OperatorExpression will take ownership
         * @param [in] operatorType the operator for which this
         * OperatorExpression will calculate
         */
        OperatorExpression(
                std::unique_ptr<ExpressionInterface<T>> &&left,
                std::unique_ptr<ExpressionInterface<T>> &&right,
                OperatorType operatorType);

        virtual ~OperatorExpression();

        boost::optional<T> calculateExpression() const override;
        std::unique_ptr<ExpressionInterface<T>> bindValueToSymbol(char glyph,
                T value) override;
        std::string toString() const override;
    private:
        using SafeOperatorFunction = boost::optional<T>(*)(T, T);

        std::unique_ptr<ExpressionInterface<T>> left_;
        std::unique_ptr<ExpressionInterface<T>> right_;
        OperatorType operatorType_;
        char operatorGlyph_;
        SafeOperatorFunction safeOperatorFunction_;
        
        // Since the modulo operator (%) is not overloaded for doubles, this 
        // stand-in function needs to take the place for all types, or else 
        // the template specialization will fail.
        static boost::optional<T> safeModulo(const T left, const T right);
        // will use the zero element in a generic way to check for division by
        // zero
        /**
         * @brief returns the zero element for the type for which this template was specialized
         * @return T the zero element for the type for which this template was specialized
         */
        static T zero();
};
}}

#endif // #ifndef OPERATOREXPRESSION_H
