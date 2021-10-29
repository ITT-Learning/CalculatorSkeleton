////////////////////////////////////////////////////////////////////////////////
/**
* @file Calculator.cpp
* @brief Function definitions for calculator
*/
////////////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include <cmath>
#include <future>
#include <iostream>
#include <sstream>
#include <thread>
#include <typeinfo>
#include <vector>

#include "Calculator.h"
#include "CalculatorMessages.h"
#include "Parser.h"
#include "ResultFactory.h"

namespace calculator {

// ***************************************************************************** /
// ***************** Calculator public methods ********************************* /
// ***************************************************************************** /
 
void Calculator::runCalculator()
{
    Parser parser;
    auto futureExpressionUnits = std::async(&Parser::getValidParsedEquationUnits, parser, parser.getUserInput());

    while (futureExpressionUnits.wait_for(std::chrono::seconds(0)) != std::future_status::ready)
    {
        std::cout << CalculatorMessages::CREATING_EQUATIONS;
    }
    std::cout << std::endl;

    Expression parsedExpression;
    auto expressionUnits = futureExpressionUnits.get();
    float answer;
    while (expressionUnits.second)
    {
        auto futureParsedExpression = std::async(&Parser::breakDownEquation, parser, expressionUnits.first);
        while (futureParsedExpression.wait_for(std::chrono::seconds(0)) != std::future_status::ready)
        {
            std::cout << CalculatorMessages::BREAKING_DOWN_AND_CALCULATING;
        }
        std::cout << std::endl;

        parsedExpression = futureParsedExpression.get();

        if(parsedExpression.isValid)
            {
            answer = calculate(parsedExpression);

            if (std::isinf(answer)) //if you divided by zero
            {
                std::cout << CalculatorMessages::ERROR_MESSAGE << CalculatorMessages::ERROR_MESSAGE_DIVIDE_BY_ZERO << std::endl;
                parsedExpression.isValid = false;
                break;
            }
            else
            {
                ExpressionUnit lastAnswer;
                lastAnswer.number = answer;
                lastAnswer.isValid = true;
                if (expressionUnits.first->size()>0)
                {
                    expressionUnits.first->insert(expressionUnits.first->begin() + parsedExpression.placementIndex, lastAnswer);
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            std::cout << CalculatorMessages::ERROR_MESSAGE << CalculatorMessages::ERROR_MESSAGE_INVALID_EXPRESSION << std::endl;
            break;
        }
    }

    if (parsedExpression.isValid)
    {
        ResultFactory resultFactory;
        std::shared_ptr<IResult> result = resultFactory.createResult(parser.getOriginalEquation(), answer);
        std::cout << result->getFullResult() << std::endl;
    }
}
    
float Calculator::calculate(const Expression &parsedExpression)
{
    float answer;

        switch (parsedExpression.operation)
        {
        case CalculatorMessages::ADD:
        {
            auto add = [](auto number1, auto number2){ return number1 + number2;}; 
            answer = add(parsedExpression.number1, parsedExpression.number2);
            break;
        }
        case CalculatorMessages::SUBTRACT:
        {
            auto subtract = [](auto number1, auto number2){ return number1 - number2;}; 
            answer = subtract(parsedExpression.number1, parsedExpression.number2);
            break;
        }
        case CalculatorMessages::MULTIPLY:
        {
            auto multiply = [](auto number1, auto number2){ return number1 * number2;}; 
            answer = multiply(parsedExpression.number1, parsedExpression.number2);
            break;
        }
        case CalculatorMessages::DIVIDE:
        {   
            auto divide = [](auto number1, auto number2){ return number1 / number2;}; 
            answer = divide(parsedExpression.number1, parsedExpression.number2);
            break;
        }
        default:
            std::cout << CalculatorMessages::ERROR_MESSAGE << std::endl;
        }

    return answer;
}

}//namespace calculator