////////////////////////////////////////////////////////////////////////////
/**
 *  @file   main.cpp
 *  @date   Fri April 16 2021
 *  @brief  Entry Point of Calculator
 */
////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>

#include "Calculator.h"
#include "CalculatorStrings.h"


int main() 
{
    int a, b;
    while(true)
    {
        std::cout << calculator::CalculatorStrings::MAIN_PROMPT << std::endl;
        std::cin >> a >> b;
        if(std::cin)
        {
            calculator::printCalculations(a,b);
        }
        else
        {
            std::cout << std::endl << std::endl << calculator::CalculatorStrings::INVALID_INPUT << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
        
        std::cout << std::endl << std::endl;
    }
}