#ifndef CALCULATORAPPLICATION_H
#define CALCULATORAPPLICATION_H

///////////////////////////////////////////////////////////////////////////////
/**
 * @file  CalculatorApplication.h
 * @date  Fri, 16 April 2021
 * 
 */
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <limits>
#include <string>

#include "CalculatorStrings.h"
#include "ICalculator.h"
#include "Parser.h"

namespace calculator {

/**
* @brief CalculatorApplication interface which exposes to other components
*
*/

class CalculatorApplication
{
    public:
        /**
         * @brief Construct a new Calculator object
         */
        CalculatorApplication() = default;

        /**
         * @brief This is the main function run in main.cpp
         * @param firstNumber [in] first number float 
         * @param secondNumber [in] second number float
         * @param operation [in] operator char
         */

        static int calculate(float firstNumber, float secondNumber, char operation, std::string originalEquation);
        
        /**
         * @brief Checks if the inputted value is within scope
         * @param number [in] value that the limit is being checked
         * @return true if within limit
         * @return otherwise false 
         */
        static bool limitCheck(float number);

        /**
         * @brief main funtion that runs the calculator
         * 
         */
        
        void runCalculator();
        
    protected:
        float firstNumber_;
        float secondNumber_;
        char  operator_; 
        float finalCalculatedAnswer_; 

};

} // namespace calculator

#endif  // CALCULATORAPPLICATION_H
