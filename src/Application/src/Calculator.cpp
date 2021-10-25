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

namespace calculator
{

//*************/
// Calculator public methods /
///
   
    void Calculator::runCalculator()
    {
        Parser parser;
        float  answer;
        Expression parsedExpression;

        auto futureVector = std::async(&Parser::createVector, parser, parser.getUserInput());
        while (futureVector.wait_for(std::chrono::seconds(0)) != std::future_status::ready)
        {
            std::cout << CalculatorMessages::CREATING_VECTOR;
        }
        std::cout << std::endl;
        auto completedVector = futureVector.get();
        while (completedVector.second)
        {
            auto futureParsedExpression = std::async(&Parser::breakDownEquation, parser, completedVector.first);
            while (futureParsedExpression.wait_for(std::chrono::seconds(0)) != std::future_status::ready)
            {
                std::cout << CalculatorMessages::BREAKING_DOWN_AND_CALCULATING;
            }
            std::cout << std::endl;
            parsedExpression = futureParsedExpression.get();

            if(parsedExpression.validExpression)
                {
                answer = calculate(parsedExpression);
                if (std::isinf(answer)) //if you divided by zero
                {
                    std::cout << CalculatorMessages::ERROR_MESSAGE << CalculatorMessages::ERROR_MESSAGE_DIVIDE_BY_ZERO << std::endl;
                    parsedExpression.validExpression = false;
                    break;
                }
                else
                {
                    ExpressionUnit lastAnswer;
                    lastAnswer.number = answer;
                    lastAnswer.valid = true;
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

        if (parsedExpression.validExpression)
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
            case '+':
            {
                auto add = [](auto a, auto b){ return a + b;}; 
                answer = add(parsedExpression.a, parsedExpression.b);
                break;
            }
            case '-':
            {
                auto subtract = [](auto a, auto b){ return a - b;}; 
                answer = subtract(parsedExpression.a, parsedExpression.b);
                break;
            }
            case 'x':
            case '*':
            {
                auto multiply = [](auto a, auto b){ return a * b;}; 
                answer = multiply(parsedExpression.a, parsedExpression.b);
                break;
            }
            case '/':
            case '%':
            {   
                auto divide = [](auto a, auto b){ return a / b;}; 
                answer = divide(parsedExpression.a, parsedExpression.b);
                break;
            }
            default:
                std::cout << CalculatorMessages::ERROR_MESSAGE << std::endl;
            }
        return answer;
    }
}//namespace calculator
