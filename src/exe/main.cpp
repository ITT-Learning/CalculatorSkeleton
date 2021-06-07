////////////////////////////////////////////////////////////////////////////
/**
 *  @file   main.cpp
 *  @date   Fri April 16 2021
 *  @brief  Entry Point of Calculator
 */
////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>


#include "SimpleExpressionCalculatorFactory.h"
#include "ICalculator.h"
#include "CalculatorStrings.h"

int main()
{
    calculator::SimpleExpressionCalculatorFactory calculatorFactory;
    while (true)
    {
        std::cout << calculator::CalculatorStrings::W2_MAIN_PROMPT << std::endl;

        std::string input;
        getline(std::cin, input);

        if(input == calculator::CalculatorStrings::EXIT)
        {
            break;
        }

        auto calculator = calculatorFactory.createCalculator(input);
        if(calculator)
        {
            std::cout << calculator->toString() << std::endl;
        }
        else
        {
            std::cout << calculator::CalculatorStrings::ERROR_MESSAGE << calculator::CalculatorStrings::ERROR_MESSAGE_INVALID_INPUT << std::endl;
        }
    }
    return 0;
}