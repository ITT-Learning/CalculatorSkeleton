///////////////////////////////////////////////////////////////////////////////
/**
 * @file  DivideCalculator.h
 * @date  Wed, 2 June 2021
 * @brief Calculator for division '/', divides the right term from the left term
 * 
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef DIVIDECALCULATOR_H
#define DIVIDECALCULATOR_H

#include "SimpleExpressionCalculator.h"

namespace calculator 
{
    class DivideCalculator: public SimpleExpressionCalculator
    {
        public:            
            static const char operation = '/';

            /**
             * @brief disable default constructor, a calculator only makes sense with inputs
             * 
             */
            DivideCalculator() = delete;

            /**
             * @brief Construct a new multiplication calculator
             *        X / Y = Z
             * @note the order of the terms do matter!
             * 
             * @param leftTerm - the X term
             * @param rightTerm - the Y term
             */
            explicit DivideCalculator(int leftTerm, int rightTerm);
            
            /**
             * @brief Get the result or the right side of the equation
             * 
             * @return int - leftTerm_ / rightTerm_
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
#endif  // DIVIDECALCULATOR_H
