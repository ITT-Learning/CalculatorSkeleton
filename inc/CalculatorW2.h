/**
 * @file CalculatorW2.h
 * @author Gary Dean Jenkins (gary.jenkins@intimetec.com)
 * @brief Class containing core calculation functionality (+ - * /)
 * @version 0.1
 * @date 2021-07-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef CALCULATORW2_H
#define CALCULATORW2_H

#include <iostream>
#include "CalculatorStrings.h"

namespace calculatorw2
{
    class CalculatorW2
    {
        public:

            /**
             * @brief Construct a new Calculator W 2 object
             * 
             */
            CalculatorW2();

            /**
             * @brief Destroy the Calculator W 2 object
             * 
             */
            ~CalculatorW2();

            /**
             * @brief Given left term, right term, and a char representationof the operation,
             *          calculate routes to, and returns value of, the correct calculation mwethod. 
             * @note A private error_ value is provided to communicate errors from the calculation methods. 
             * @param IN left 
             * @param IN right 
             * @param IN op 
             * @return double 
             */
            double calculate(double left, double right, char op);

            /**
             * @brief Calculates and returns the sum of the left and right terms.
             * 
             * @param IN left 
             * @param IN right 
             * @return double 
             */
            double add(double left, double right);

            /**
             * @brief Calculates and returns the subtraction of the right term from the left term.
             * 
             * @param IN left 
             * @param IN right 
             * @return double 
             */
            double subtract(double left, double right);

            /**
             * @brief Calculates and returns the product of the left and right terms.
             * 
             * @param IN left 
             * @param IN right 
             * @return double 
             */
            double multiply(double left, double right);

            /**
             * @brief Calculates and returns the division of the left term by the right term.
             * @note If the right term is 0, error_ is set to a divide by zero error string.
             * 
             * @param IN left 
             * @param IN right 
             * @return double 
             */
            double divide(double left, double right);

            /**
             * @brief Get the Error object
             * 
             * @return const char* 
             */
            const char* getError();

        private:

            /**
             * @brief pointer to simple string containing an error description.
             * 
             */
            const char* error_;
    };
}

#endif  // CALCULATORW2_H