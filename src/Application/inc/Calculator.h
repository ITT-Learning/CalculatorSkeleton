#ifndef CALCULATOR_H
#define CALCULATOR_H

////////////////////////////////////////////////////////////////////////////////
/**
* @file Calculator.h
* @brief calculator function declarations.
*/
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
namespace calculator
{
    class Calculator
    {
        public:
            /**
             * @brief initiates calculator and asks for inputs, then runs the validate function
             * @param number1 is first number entered
             * @param number2 is second number entered
             * @param operation is the operator entered (+, - , / or % , * or x)
            */
            void runCalculator();

            /**
             * @brief takes in a string for calculator and validates input
             * @param operation is the operator entered (+, - , / or % , * or x)
            */
            bool validateInput(const std::string &input);

            /**
             * @brief Runs a switch statement with entered operator, and then chooses the correct 
             * function to return the calculated float then writes answer to the console
             * @param answer is what is returned from the different math functions, 
             * and used to write to the console.
            */
            float calculate(char operation, float number1, float number2);
    };

}//namespace calculator
#endif  // CALCULATOR_H