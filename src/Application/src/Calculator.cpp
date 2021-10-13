////////////////////////////////////////////////////////////////////////////////
/**
* @file Calculator.cpp
* @brief Function definitions for calculator
*/
////////////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
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

        std::vector<ExpressionUnit> equationVector = parser.createVector(parser.getUserInput());
        float answer;

        while (equationVector.size() > 1)
        {
           Expression parsedExpression = parser.parseFullEquation(equationVector);
           answer = calculate(parsedExpression.operation, parsedExpression.a, parsedExpression.b);
           
            if (std::isinf(answer)) //if you divided by zero
            {
                std::cout << CalculatorMessages::ERROR_MESSAGE << CalculatorMessages::ERROR_MESSAGE_DIVIDE_BY_ZERO << std::endl;
                break;
            }

           else
           {
               ExpressionUnit lastAnswer;
               lastAnswer.number = answer;
               equationVector.insert(equationVector.begin() + parsedExpression.placementIndex, lastAnswer);
           }
        }
            ResultFactory resultFactory;
            std::shared_ptr<IResult> result = resultFactory.createResult(parser.originalEquation, answer);
            std::cout << result->getFullResult() << std::endl;
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

