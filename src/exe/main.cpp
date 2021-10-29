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
    bool running = true;
    while(running)
    {
        calculator::Calculator calculator;
        calculator.runCalculator();

        std::cout << calculator::CalculatorMessages::RETRY_MESSAGE << std::endl;
        
        std::string response;
        std::cin >> response;
        if (response[0] != 'y' && response[0] != 'Y') // didn't save 'y's in messages since only using here
        {
            std::cout << calculator::CalculatorMessages::OUTRO_MESSAGE << std::endl;
            running = false;
        }
    }

    return 0;
}
