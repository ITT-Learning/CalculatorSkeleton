////////////////////////////////////////////////////////////////////////////
/**
 *  @file   main.cpp
 *  @date   Fri April 16 2021
 *  @brief  Entry Point of Calculator
 */
////////////////////////////////////////////////////////////////////////////

#include "../inc/Calculator.h"

using namespace Calculator;

int main() 
{
    std::cout << "Welcome to the Calculator C++ learning project.\n";
    std::cout << "- Enter \"help\" for help.\n";
    std::cout << "- Enter \"quit\" to quit.\n" << std::endl;

    Calculator::Calculator calculator;
    calculator.run();
}
