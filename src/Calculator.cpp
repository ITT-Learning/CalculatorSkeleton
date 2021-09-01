////////////////////////////////////////////////////////////////////////////
/**
 *  @file   Calculator.cpp
 *  @date   Fri April 16 2021
 *  @brief  These are the functions that are used by main.cpp
 */
////////////////////////////////////////////////////////////////////////////

#include "Calculator.h"

namespace Calculator
{
        //*************/
        // Calculator public methods /
        ///
        void Week1::calculator(){
                float number1, number2;
                std::cout << "Welcome to the Calculator C++ learning project." << std::endl;
                std::cout << "Please enter in two numbers separated by a space" << std::endl;
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
}