////////////////////////////////////////////////////////////////////////////
/**
 *  @file   Calculator.cpp
 *  @date   Fri April 16 2021
 *  @brief  Funtions that support main.cpp
 */
////////////////////////////////////////////////////////////////////////////

#include "Calculator.h"
// Add Function definitions here.

void printCalculations(int a, int b)
{
    std::cout << std::endl;
    std::cout << formatCalculation(a, b, a + b, '+');
    std::cout << formatCalculation(a, b, a * b, 'X');
    std::cout << formatCalculation(a, b, b == 0 ? 0 : a / b, '%');
    std::cout << formatCalculation(a, b, a - b, '-');
}

//is this even better?
std::string formatCalculation(int a, int b, int result, char operation)
{
    return "" + std::to_string(a) + " " + operation + " " + std::to_string(b) + " = " + std::to_string(result) + "\n"; //is there a better way to do this in c++ 11? Like std::format from c++ 20
}