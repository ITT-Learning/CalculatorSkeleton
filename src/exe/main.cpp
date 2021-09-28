////////////////////////////////////////////////////////////////////////////
/**
 *  @file   main.cpp
 *  @brief  Entry Point of Calculator
 */
////////////////////////////////////////////////////////////////////////////

#include "Calculator.h"
#include "CalculatorMessages.h"
#include <string>

int main() 
{
    while(true)
    {
        calculator::Calculator c;
        std::string response;

        c.runCalculator();

        std::cout << calculator::CalculatorMessages::RETRY_MESSAGE << std::endl;
        std::cin >> response;
        {
            if (response[0] != 'y' &&  response[0] != 'Y')
            {
                std::cout << calculator::CalculatorMessages::OUTRO_MESSAGE << std::endl;
                return 0;
            }
        }

    }
}