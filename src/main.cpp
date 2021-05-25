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
    std::istream &refcin = std::cin;
    while(true)
    {
        std::cout << "Enter two numbers, e.g. '4 10':\n(ctrl-c to exit)" << std::endl;
        refcin >> a >> b;
        if(refcin)
        {
            printCalculations(a,b);

        }
        else
        {
            std::cout << std::endl << std::endl << "Invalid format please try again." << std::endl;
            refcin.clear();
            refcin.ignore();
        }
        
        std::cout << std::endl << std::endl;
    }
}