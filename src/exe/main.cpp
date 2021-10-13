////////////////////////////////////////////////////////////////////////////
/**
 *  @file   main.cpp
 *  @brief  Entry Point of Calculator
 */
////////////////////////////////////////////////////////////////////////////

#include <string>

#include "Calculator.h"
#include "CalculatorMessages.h"

int main() 
{
    while(true)
    {
        calculator::Calculator calculator;
        std::string response;

        calculator.runCalculator();

        std::cout << calculator::CalculatorMessages::RETRY_MESSAGE << std::endl;
        
        std::cin >> response;
        if (response[0] != 'y' &&  response[0] != 'Y')
        {
            std::cout << calculator::CalculatorMessages::OUTRO_MESSAGE << std::endl;
            return 0;
        }
    }
}
