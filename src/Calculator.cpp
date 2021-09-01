////////////////////////////////////////////////////////////////////////////
/**
 *  @file   Calculator.cpp
 *  @date   Fri April 16 2021
 *  @brief  These are the functions that are used by main.cpp
 */
////////////////////////////////////////////////////////////////////////////

#include "Calculator.h"
// Add Function definitions here.
////////////////////////////////////////////////////////////////////////////
/**
 *  @brief  calculator function which asks user for two inputted values. 
 *  @return returns output to console of user values into equations with the math completed
 */
////////////////////////////////////////////////////////////////////////////
void Calculator::calculator(){
        float number1, number2;
        std::cin >> number1 >> number2;
        int addResult = number1 + number2;
        int multiplyResult = number1 * number2;
        float divideResult = number1 / number2;
        int subtractResult = number1 - number2;
        std::cout << number1 << " + " << number2 << " = " << addResult << std::endl; 
        std::cout << number1 << " X " << number2 << " = " << multiplyResult << std::endl;
        std::cout << number1 << " % " << number2 << " = " << divideResult << std::endl;
        std::cout << number1 << " - " << number2 << " = " << subtractResult << std::endl;
}