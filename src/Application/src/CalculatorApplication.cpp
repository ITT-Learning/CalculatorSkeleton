////////////////////////////////////////////////////////////////////////////
/**
 *  @file   CalculatorApplication.cpp
 *  @date   Fri April 16 2021
 *  @brief  These are the functions that are used by main.cpp
 */
////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <limits>
#include <sstream>
#include <string>


#include "CalculatorApplication.h"
#include "CalculatorApplicationFactory.h"
#include "CalculatorStrings.h"
namespace calculator
{

    int CalculatorApplication::calculate(float a, float b, char op)
    {
        calculator::CalculatorApplicationFactory calculatorAppFactory;  
        
        if(limitCheck(a) && limitCheck(b))
        {
            auto calculator = calculatorAppFactory.createCalculator(a, b, op); //variables placed into createCalc function and placed into calculator variable
            if(calculator)
            {
                std::cout << calculator->toString() << std::endl; //if calculator returned from function is valid, point to string function and output expression and result
            }
            else
            {
                std::cout << CalculatorStrings::ERROR_MESSAGE_INVALID_INPUT << std::endl;
            }
        }
        else
        {
            return -1;
        }
        return 0;
    }

    std::string CalculatorApplication::toString()
    {
        return std::to_string(firstNumber_) + " " + op_ + " " + std::to_string(secondNumber_) + " = " + std::to_string(getResult());
    }

    bool CalculatorApplication::limitCheck(float a)
    {
        if(a > std::numeric_limits<float>::max())
        {
            std::cerr << CalculatorStrings::ERROR_MESSAGE_INPUT_TOO_LARGE << std::endl;
            return false;
        }
        else if(a < std::numeric_limits<float>::min())
        {
            std::cerr << CalculatorStrings::ERROR_MESSAGE_INPUT_TOO_SMALL << std::endl;
            return false;
        }
        else if(a == std::numeric_limits<float>::infinity())
        {
            std::cerr << CalculatorStrings::ERROR_MESSAGE_INPUT_TOO_LARGE << std::endl;
            return false;
        }
        return true;
    }
    

}