////////////////////////////////////////////////////////////////////////////
/**
 *  @file   main.cpp
 *  @date   Fri April 16 2021
 *  @brief  Entry Point of Calculator
 */
////////////////////////////////////////////////////////////////////////////
#include <iostream>

#include "Calculator.h"

int main() 
{
    // Fill in or change code here as necessary.  See also Calculator.cpp
    int a, b;
    while(true)
    {
        std::cout << "Enter two numbers, e.g. '4 10':\n(ctrl-c to exit)" << std::endl;
        std::cin >> a >> b;
        printCalculations(a,b);
        std::cout << std::endl << std::endl;
    }
}