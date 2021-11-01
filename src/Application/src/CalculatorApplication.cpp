////////////////////////////////////////////////////////////////////////////
/**
 *  @file   CalculatorApplication.cpp
 *  @date   Fri April 16 2021
 *  @brief  These are the functions that are used by main.cpp
 */
////////////////////////////////////////////////////////////////////////////

#include <future>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
<<<<<<< HEAD
=======
#include <thread>
>>>>>>> 2085be165f0cff9b9b8d290c375838c98aaaabb9

#include "CalculatorApplication.h"
#include "CalculatorApplicationFactory.h"
#include "CalculatorStrings.h"
<<<<<<< HEAD
=======

>>>>>>> 2085be165f0cff9b9b8d290c375838c98aaaabb9
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
<<<<<<< HEAD
        auto calculator = calculatorAppFactory.createCalculator(firstNumber, secondNumber, operation); //variables placed into createCalc function and placed into calculator variable
        if(calculator)
        {
            std::cout << calculator->toString() << std::endl; //if calculator returned from function is valid, point to string function and output expression and result
=======
        auto calculator = calculatorAppFactory.createCalculator(firstNumber, secondNumber, operation);
        if(calculator)
        {
            result = calculator->getResult();
            std::cout << calculator->toString() << std::endl;
>>>>>>> 2085be165f0cff9b9b8d290c375838c98aaaabb9
        }
        else
        {
            std::cout << CalculatorStrings::ERROR_MESSAGE_INVALID_INPUT << std::endl;
        }
    }
    else
<<<<<<< HEAD
    {
        result = -1;
=======
    {
        result = -1;
    }

    return result;
}

void CalculatorApplication::runCalculator()
{
    Parser parser;
    float answer;
    Expression parsedExpression;

    auto tempExpressionUnits = std::async(&Parser::createVector, parser, parser.getUserInput());
    while(tempExpressionUnits.wait_for(std::chrono::seconds(0)) != std::future_status::ready)
    {
        std::cout << CalculatorStrings::BUILDING_VECTORS;
>>>>>>> 2085be165f0cff9b9b8d290c375838c98aaaabb9
    }
    std::cout << std::endl;
    auto setExpressionUnits = tempExpressionUnits.get();

<<<<<<< HEAD
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
=======
    while(setExpressionUnits.second)
    {
        auto tempParsedExpression = std::async(&Parser::breakDownEquation, parser, setExpressionUnits.first);
        while(tempParsedExpression.wait_for(std::chrono::seconds(0)) != std::future_status::ready)
        {
            std::cout << CalculatorStrings::DISSECTING_AND_CALCULATING;
        }
        std::cout << std::endl;

        parsedExpression = tempParsedExpression.get();

        if(parsedExpression.validExpression)
        {
            answer = CalculatorApplication::calculate(parsedExpression.firstNumber, parsedExpression.secondNumber, parsedExpression.operation);
            ExpressionUnit prevAnswer;
            prevAnswer.number = answer;
            prevAnswer.valid = true;

            if(setExpressionUnits.first->size() > 0)
            {
                setExpressionUnits.first->insert(setExpressionUnits.first->begin() + parsedExpression.placementIndex, prevAnswer);
            }
            else
            {
                break;
            }
            
        }
        else
        {
            std::cout << CalculatorStrings::ERROR_MESSAGE_INVALID_INPUT << std::endl;
            break;
        }

    }
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
>>>>>>> 2085be165f0cff9b9b8d290c375838c98aaaabb9
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
<<<<<<< HEAD
=======
    
>>>>>>> 2085be165f0cff9b9b8d290c375838c98aaaabb9
    return result;
}

} //namespace calculator
