///////////////////////////////////////////////////////////////////////////////
/**
 * @file  MultiplyCalculatorW3.h
 * @date  Wed, 2 June 2021
 * @brief Calculator for multiplication '*', multiplies the terms together
 * 
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef MULTIPLYCALCULATORW3_H
#define MULTIPLYCALCULATORW3_H

#include "SimpleExpressionCalculatorW3.h"

namespace calculator 
{
    class MultiplyCalculatorW3: public SimpleExpressionCalculatorW3
    {
        public:            
            static const char operation = '*';

            /**
             * @brief disable default constructor, a calculator only makes sense with inputs
             * 
             */
            MultiplyCalculatorW3() = delete;

            /**
             * @brief Construct a new multiplication calculator
             *        X * Y = Z
             * @note due to the associative property the order of the terms do not matter
             * 
             * @param leftTerm - the X term
             * @param rightTerm - the Y term
             */
            explicit MultiplyCalculatorW3(int leftTerm, int rightTerm);
            
            /**
             * @brief Get the result or the right side of the equation
             * 
             * @return int - leftTerm_ * rightTerm_
             */
            int getResult() override;
        private:
            /**
             * @brief get the operation of the calculator, i.e. operation_
             * 
             * @return char operation_
             */
            char getOperation() override;
    };
}
#endif  // MULTIPLYCALCULATORW3_H
