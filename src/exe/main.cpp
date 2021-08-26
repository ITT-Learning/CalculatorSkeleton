////////////////////////////////////////////////////////////////////////////
/**
 *  @file   main.cpp
 *  @brief  Entry Point of Calculator
 */
////////////////////////////////////////////////////////////////////////////

#include "Calculator.h"
#include "CalculatorMessages.h"

int main() 
{
    while(true)
    {
        calculator::Calculator c;
        char loop;

        c.runCalculator();

        std::cout << calculator::CalculatorMessages::RETRY_MESSAGE << std::endl;
        std::cin >> loop;
        if (loop != 'y' &&  loop != 'Y')
        {
            std::cout << calculator::CalculatorMessages::OUTRO_MESSAGE << std::endl;
            return 0;
        }
    }
}