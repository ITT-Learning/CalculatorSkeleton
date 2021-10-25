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
namespace calculator {

// *****************************************************************************/
// ***************** CalculatorApplication public methods **********************/
// *****************************************************************************/

int CalculatorApplication::calculate(float firstNumber, float secondNumber, char operation)
{
    int result = 0;

    if(limitCheck(firstNumber) && limitCheck(secondNumber))
    {
        calculator::CalculatorApplicationFactory calculatorAppFactory;  
        auto calculator = calculatorAppFactory.createCalculator(firstNumber, secondNumber, operation); //variables placed into createCalc function and placed into calculator variable
        if(calculator)
        {
            result = calculator->getResult();
            std::cout << calculator->toString() << std::endl; //if calculator returned from function is valid, point to string function and output expression and result
        }
        else
        {
            std::cout << CalculatorStrings::ERROR_MESSAGE_INVALID_INPUT << std::endl;
        }
    }
    else
    {
        result = -1;
    }

    return result;
}

std::string CalculatorApplication::toString()
{
    return std::to_string(firstNumber_) + CalculatorStrings::EMPTY_SPACE + operator_ + CalculatorStrings::EMPTY_SPACE + std::to_string(secondNumber_) + CalculatorStrings::EQUAL_SIGN + std::to_string(getResult());
}

bool CalculatorApplication::limitCheck(float firstNumber)
{
    bool result = true;
    if(firstNumber > std::numeric_limits<float>::max())
    {
        std::cerr << CalculatorStrings::ERROR_MESSAGE_INPUT_TOO_LARGE << std::endl;
        result = false;
    }
    else if(firstNumber < std::numeric_limits<float>::min())
    {
        std::cerr << CalculatorStrings::ERROR_MESSAGE_INPUT_TOO_SMALL << std::endl;
        result = false;
    }
    else if(firstNumber == std::numeric_limits<float>::infinity())
    {
        std::cerr << CalculatorStrings::ERROR_MESSAGE_INPUT_TOO_LARGE << std::endl;
        result = false;
    }
    return result;
}

} //namespace calculator
