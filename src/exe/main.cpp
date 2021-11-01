////////////////////////////////////////////////////////////////////////////
/**
 *  @file   main.cpp
 *  @date   Fri August 25 2021
 *  @brief  This is a basic calculator program which asks for an equation and uses a switch to decifer what the equation is and return the result
 */
////////////////////////////////////////////////////////////////////////////

#include "CalculatorApplication.h"
#include "CalculatorStrings.h"
#include "Parser.h"
#include "History.h"

using namespace calculator;
/**
 * @brief Main interface which exposes to other components
 *
 */
int main() 
{
    bool again = true;

    while(again)
    {
        CalculatorApplication calculatorApplication;
        calculatorApplication.runCalculator();

        std::cout << CalculatorStrings::REPEAT_PROGRAM << std::endl;
        
        char repeat;      
        std::cin >> repeat; 
 
        if(repeat != CalculatorStrings::YES)
        {
            again = false;
        }
    }

    return 0;
    
} // namespace calculator
