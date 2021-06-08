
////////////////////////////////////////////////////////////////////////////
/**
 *  @file   CalculatorApp.cpp
 *  @date   Fri April 16 2021
 *  @brief
 */
////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cmath>

#include "CalculatorApplication.h"
#include "CalculatorStrings.h"
#include "SimpleExpressionCalculatorFactory.h"
#include "CustomCalculator.h"
#include "CustomCalculatorFactory.h"

namespace calculator
{
    void CalculatorApplication::runW3()
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
    }

    void CalculatorApplication::run()
    {
        CustomCalculator<int> c({100}, [](auto f){return std::sqrt(f[0]);}, "sqrt({} {})");

        std::cout << c.toString() << std::endl;
    }

}