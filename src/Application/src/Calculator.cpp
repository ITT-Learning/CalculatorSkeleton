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
        std::pair<std::shared_ptr<std::vector<ExpressionUnit>>,bool> completedVector;

        auto futureVector = std::async(&Parser::createVector, parser, parser.getUserInput());

        futureVector.wait();

        completedVector = futureVector.get();

        while (completedVector.second)
        {
            parsedExpression = parser.breakDownEquation(completedVector.first);

            
            if(parsedExpression.validExpression)
                {
                answer = calculate(parsedExpression.operation, parsedExpression.a, parsedExpression.b);
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
            std::shared_ptr<IResult> result = resultFactory.createResult(parser.originalEquation, answer);
            std::cout << result->getFullResult() << std::endl;
        }
    }
     
    float Calculator::calculate(char operation, float number1, float number2)
    {
        float answer;

            switch (operation)
            {
            case '+':
            {
                auto add = [](auto a, auto b){ return a + b;}; 
                answer = add(number1, number2);
                break;
            }
            case '-':
            {
                auto subtract = [](auto a, auto b){ return a - b;}; 
                answer = subtract(number1, number2);
                break;
            }
            case 'x':
            case '*':
            {
                auto multiply = [](auto a, auto b){ return a * b;}; 
                answer = multiply(number1, number2);
                break;
            }
            case '/':
            case '%':
            {   
                auto divide = [](auto a, auto b){ return a / b;}; 
                answer = divide(number1, number2);
                break;
            }
            default:
                std::cout << CalculatorMessages::ERROR_MESSAGE << std::endl;
            }
        return answer;
    }
}//namespace calculator

