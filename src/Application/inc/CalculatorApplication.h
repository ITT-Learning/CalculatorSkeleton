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
 * @brief This is the Class containing the functions and variables used in week 1
 */
class CalculatorApplication : public ICalculator
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
        static int calculate(float firstNumber, float secondNumber, char operation);
        
        /**
         * @brief Get the Result object. Pure virtual function defined in child classes
         * @return float after value calculated has been returned
         */
        virtual float getResult() = 0;

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
        static void runCalculator();
        
        /**
         * @name ICalculator method.
         * @{
         */
        
        std::string toString() override;
        
        /**
         * @}
         */

    protected:
        float firstNumber_;
        float secondNumber_;
        char  operator_; 

};

} // namespace calculator

#endif  // CALCULATORAPPLICATION_H
