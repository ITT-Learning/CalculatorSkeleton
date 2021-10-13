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
             * @brief initiates calculator and works with the parser to return a result object
             * @param futureVector is the thread for a created vector object
             * @param futureParsedExpression is the thread for a created expression object 
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
