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
    auto futureVector = std::async(&Parser::createVector, parser, parser.getUserInput());

    while (futureVector.wait_for(std::chrono::seconds(0)) != std::future_status::ready)
    {
        std::cout << CalculatorMessages::CREATING_VECTOR;
    }
    std::cout << std::endl;

    Expression parsedExpression;
    auto completedVector = futureVector.get();
    float answer;
    while (completedVector.second)
    {
        auto futureParsedExpression = std::async(&Parser::breakDownEquation, parser, completedVector.first);
        while (futureParsedExpression.wait_for(std::chrono::seconds(0)) != std::future_status::ready)
        {
            std::cout << CalculatorMessages::BREAKING_DOWN_AND_CALCULATING;
        }
        std::cout << std::endl;

        parsedExpression = futureParsedExpression.get();

        if(parsedExpression.isValidExpression)
            {
            answer = calculate(parsedExpression);

            if (std::isinf(answer)) //if you divided by zero
            {
                std::cout << CalculatorMessages::ERROR_MESSAGE << CalculatorMessages::ERROR_MESSAGE_DIVIDE_BY_ZERO << std::endl;
                parsedExpression.isValidExpression = false;
                break;
            }
            else
            {
                ExpressionUnit lastAnswer;
                lastAnswer.number = answer;
                lastAnswer.isValid = true;
                if (completedVector.first->size()>0)
                {
                    completedVector.first->insert(completedVector.first->begin() + parsedExpression.placementIndex, lastAnswer);
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

    if (parsedExpression.isValidExpression)
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
        case CalculatorMessages::OPERATIONS[0]:
        {
            auto add = [](auto number1, auto number2){ return number1 + number2;}; 
            answer = add(parsedExpression.number1, parsedExpression.number2);
            break;
        }
        case CalculatorMessages::OPERATIONS[1]:
        {
            auto subtract = [](auto number1, auto number2){ return number1 - number2;}; 
            answer = subtract(parsedExpression.number1, parsedExpression.number2);
            break;
        }
        case CalculatorMessages::OPERATIONS[4]:
        case CalculatorMessages::OPERATIONS[5]:
        {
            auto multiply = [](auto number1, auto number2){ return number1 * number2;}; 
            answer = multiply(parsedExpression.number1, parsedExpression.number2);
            break;
        }
        case CalculatorMessages::OPERATIONS[2]:
        case CalculatorMessages::OPERATIONS[3]:
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
