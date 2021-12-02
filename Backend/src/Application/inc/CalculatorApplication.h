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
         * @param [in] firstNumber first number float 
         * @param [in] secondNumber second number float
         * @param [in] operation operator char
         */

        static float calculate(float firstNumber, float secondNumber, char operation, const std::string &originalEquation);
        
        /**
         * @brief Checks if the inputted value is within scope
         * @param [in] number value that the limit is being checked
         * @return true if within limit
         * @return otherwise false 
         */
        static bool limitCheck(float number);

        /**
         * @brief runCalculator function that runs the calculator on the server
         * @param [in] webInput string passed in by website/input from website
         * @return string which is the final answer, and bool which states if successful or not 
         */
        std::pair<std::string, bool> runCalculator(std::string webInput);
        
    protected:
        float firstNumber_;
        float secondNumber_;
        char  operator_; 
        float finalCalculatedAnswer_; 

};

} // namespace calculator

#endif  // CALCULATORAPPLICATION_H
