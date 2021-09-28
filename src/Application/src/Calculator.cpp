////////////////////////////////////////////////////////////////////////////////
/**
* @file Calculator.cpp
* @brief Function definitions for calculator
*/
////////////////////////////////////////////////////////////////////////////////

#include "Calculator.h"
#include "Parser.h"
#include <stdlib.h>
#include <iostream>
#include <typeinfo>
#include "CalculatorMessages.h"
#include <sstream>
#include <math.h>
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
            Result result = resultFactory.CreateResult(parsedExpression, answer);

            if (isinf(answer)) //if you divided by zero
            {
                std::cout << CalculatorMessages::ERROR_MESSAGE << CalculatorMessages::ERROR_MESSAGE_DIVIDE_BY_ZERO << std::endl;
            }
            else
            {
                result.returnResult();
            }
        }
    }
    
    float Calculator::calculate(char operation, float number1, float number2)
    {
        double answer;

            switch (operation)
            {
            case '+':
            {
                answer = add(number1, number2);
                break;
            }
            case '-':
            {
                answer = subtract(number1, number2);
                break;
            }
            case 'x':
            {
                answer = multiply(number1, number2);
                break;
            }
            case '*':
            {
                answer = multiply(number1, number2);
                break;
            }
            case '/':
            {   
                answer = divide(number1, number2);
                break;
            }
            case '%':
            {
                answer = divide(number1, number2);
                break;
            }
            default:
                std::cout << CalculatorMessages::ERROR_MESSAGE << std::endl;
            }
        return answer;
    }

    //*************/
    // Calculator private methods /
    ///

    float Calculator::add(double number1, double number2)
    {
        return number1 + number2;
    }

    float Calculator::subtract(double number1, double number2)
    {
        return number1 - number2;
    }

    float Calculator::divide(double number1, double number2)
    {
        float ans = number1 / number2;
        return ans;
    }

    float Calculator::multiply(double number1, double number2)
    {
        return number1 * number2;
    }

}//namespace calculator
