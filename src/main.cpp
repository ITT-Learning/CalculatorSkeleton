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

int main()
{
    while (true)
    {
        std::cout << "Input a simple math expression e.g., '5 + 5' " << std::endl <<
                     "Valid operations are [+-/*]" << std::endl <<
                     "(Enter 'exit' to quit)" << std::endl;
        
        std::string input;
        getline(std::cin, input);

        if(input == "exit")
            break;
        
        Calculator c(input);
        std::cout << c << std::endl;
    }
    return 0;
}