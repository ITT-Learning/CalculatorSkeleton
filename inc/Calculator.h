////////////////////////////////////////////////////////////////////////////////
/**
* @file Calculator.h
* @brief calculator function declarations.
*/
////////////////////////////////////////////////////////////////////////////////

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>

namespace calculator{

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

}//namespace calculator

#endif  // CALCULATOR_H