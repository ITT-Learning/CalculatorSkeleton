////////////////////////////////////////////////////////////////////////////////
/**
* @file Calculator.cpp
* @brief Function definitions for calculator
*/
////////////////////////////////////////////////////////////////////////////////

#include <cmath>
#include <iostream>
#include <sstream>
#include <typeinfo>

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
        Parser p;
        Expression parsedExpression = p.parseFullEquation(p.getUserInput());
        
        if (parsedExpression.valid)
        {
            ResultFactory resultFactory;
            float answer = calculate(parsedExpression.operation, parsedExpression.a, parsedExpression.b);
            std::shared_ptr<IResult> result = resultFactory.createResult(parsedExpression, answer);

            if (std::isinf(answer)) //if you divided by zero
            {
                std::cout << CalculatorMessages::ERROR_MESSAGE << CalculatorMessages::ERROR_MESSAGE_DIVIDE_BY_ZERO << std::endl;
            }
            else
            {
                std::cout << result->getFullResult() << std::endl;
            }
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

