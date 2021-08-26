////////////////////////////////////////////////////////////////////////////////
/**
* @file Calculator.h
* @brief calculator function declarations.
*/
////////////////////////////////////////////////////////////////////////////////

#ifndef CALCULATOR_H
#define CALCULATOR_H

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
            bool validateInput(std::string input);

            /**
             * @brief Runs a switch statement with entered operator, and then chooses the correct 
             * function to return the calculated float then writes answer to the console
             * @param answer is what is returned from the different math functions, 
             * and used to write to the console.
            */
            float calculate(const char &operation, const float &number1, const float &number2);

        private:

             /**
             * @brief This variable is used to keep track of the entire equation built out so far
            */
            std::string fullEquation;

            /**
             * @brief takes in input
             * @returns string of input entered
            */
            std::string getUserInput();

            /**
             * @brief adds num1 and num2 together
             * @returns a float of the result
            */
            float add(double num1, double num2);

            /**
             * @brief subtracts num2 from num1
             * @returns a float of the result
            */
            float subtract(double num1, double num2);

            /**
             * @brief divides num1 over num2
             * @returns a float of the result
            */
            float divide(double num1, double num2);

            /**
             * @brief multiples num1 and num2
             * @returns a float of the result
            */
            float multiply(double num1, double num2);
    };
}//namespace calculator
#endif  // CALCULATOR_H