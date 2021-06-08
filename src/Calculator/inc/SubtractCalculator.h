///////////////////////////////////////////////////////////////////////////////
/**
 * @file  SubtractCalculator.h
 * @date  Wed, 2 June 2021
 * @brief Calculator for subtraction '-', subtracts the right term from the left term
 * 
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef SUBTRACTCALCULATOR_H
#define SUBTRACTCALCULATOR_H

#include "SimpleExpressionCalculator.h"

namespace calculator 
{
    class SubtractCalculator: public SimpleExpressionCalculator
    {
        public:            
            static const char operation = '-';

            /**
             * @brief disable default constructor, a calculator only makes sense with inputs
             * 
             */
            SubtractCalculator() = delete;

            /**
             * @brief Construct a new multiplication calculator
             *        X - Y = Z
             * @note the order of the terms do not matter!
             * 
             * @param leftTerm - the X term
             * @param rightTerm - the Y term
             */
            explicit SubtractCalculator(int leftTerm, int rightTerm);

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
#endif  // SUBTRACTCALCULATOR_H
