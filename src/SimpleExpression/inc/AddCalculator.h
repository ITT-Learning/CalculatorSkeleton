///////////////////////////////////////////////////////////////////////////////
/**
 * @file  AddCalculator.h
 * @date  Wed, 2 June 2021
 * @brief Calculator for addition '+', adds two terms together
 * 
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef ADDCALCULATOR_H
#define ADDCALCULATOR_H

#include "SimpleExpressionCalculator.h"

namespace calculator 
{
    class AddCalculator: public SimpleExpressionCalculator
    {
        public:            
            static const char operation = '+';

            /**
             * @brief disable default constructor, a calculator only makes sense with inputs
             * 
             */
            AddCalculator() = delete;

            /**
             * @brief Construct a new multiplication calculator
             *        X + Y = Z
             * @note due to the communitive property the order of the terms do not matter
             * 
             * @param leftTerm - the X term
             * @param rightTerm - the Y term
             */
            explicit AddCalculator(int leftTerm, int rightTerm);

            /**
             * @brief Get the result or the right side of the equation
             * 
             * @return int - leftTerm_ + rightTerm_
             */
            int getResult() const final;
        private:
            /**
             * @brief get the operation of the calculator, i.e. operation_
             * 
             * @return char operation_
             */
            char getOperation() const final;
    };
}
#endif  // ADDCALCULATOR_H
