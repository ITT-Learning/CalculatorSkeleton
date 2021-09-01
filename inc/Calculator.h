#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>

////////////////////////////////////////////////////////////////////////////////
/**
* @file Calculator.h
* @brief calculator function declarations.
*/
////////////////////////////////////////////////////////////////////////////////
namespace calculator{
    class Calculator{
        public:
            /**
             * @brief initiates calculator and asks for inputs, then runs the calculate function
             * @param num1 is first number entered
             * @param num2 is second number entered
             * @param operation is the operator entered (+, - , / or % , * or x)
            */
            void runCalculator();

            /**
             * @brief Runs a switch statement with entered operator, and then chooses the correct 
             * function to return the calculated float then writes answer to the console
             * @param answer is what is returned from the different math functions, 
             * and used to write to the console.
            */
            void calculate(const char &calcType, const double &num1, const double &num2);

        private:
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