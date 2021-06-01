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
    while (true)
    {
        std::cout << calculator::CalculatorStrings::W2_MAIN_PROMPT << std::endl;
        
        std::string input;
        getline(std::cin, input);

        if(input == calculator::CalculatorStrings::EXIT)
            break;
        
        calculator::Calculator calculator(input);
        std::cout << calculator << std::endl;
    }
    return 0;
}