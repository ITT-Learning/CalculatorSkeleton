////////////////////////////////////////////////////////////////////////////
/**
 *  @file   main.cpp
 *  @date   Fri April 16 2021
 *  @brief  Entry Point of CalculatorW2
 */
////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>


#include "CalculatorW2.h"
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
        
        calculator::CalculatorW2 calculator(input);
        std::cout << calculator << std::endl;
    }
    return 0;
}