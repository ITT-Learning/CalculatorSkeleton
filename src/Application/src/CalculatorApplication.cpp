////////////////////////////////////////////////////////////////////////////
/**
 *  @file   CalculatorApplication.cpp
 *  @date   Fri April 16 2021
 *  @brief  These are the functions that are used by main.cpp
 */
////////////////////////////////////////////////////////////////////////////

#include "CalculatorStrings.h"
#include "CalculatorApplication.h"
#include <iostream>
#include <limits>

namespace calculator
{
    //*************/
    // Calculator public methods /
    ///
    float CalculatorApplication::add (float number1, float number2)
    {
        float result = number1 + number2;
        return result;    
    }
    void CalculatorApplication::calculate()
    {
        float number1, number2;
        char op;
        std::cout << CalculatorStrings::WELCOME_MESSAGE << std::endl;
        std::cout << CalculatorStrings::ENTER_EQUATION << std::endl;
        std::cin >> number1 >> op >>  number2;
        while(1)
        {
            if(std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << CalculatorStrings::ERROR_MESSAGE_INVALID_INPUT << std::endl;
                std::cout << CalculatorStrings::RE_ENTER_EQUATION << std::endl;
                std::cin >> number1 >> op >> number2;
            }
            if(!std::cin.fail())
            {
                break;
            }
        }
        CalculatorApplication calculator;
        switch(op)
        {
            case '+':
            {
                std::cout << number1 << op << number2 << " = " << calculator.add(number1, number2) << std::endl;
                break;
            }
            case '*':
            {
                std::cout << number1 << op << number2 << " = " << calculator.multiply(number1, number2) << std::endl;
                break;
            }
            case '/':
            {
                std::cout << number1 << op << number2 << " = " << calculator.divide(number1, number2) << std::endl;
                break;
            }
            case '-':
            {
                std::cout << number1 << op << number2 << " = " << calculator.subtract(number1, number2) << std::endl;                
                break;
            }
            case '%':
            {
                std::cout << number1 << op << number2 << " = " << calculator.modulus(number1, number2) << std::endl;
                break;
            }
            default:
            {
                std::cerr << CalculatorStrings::ERROR_MESSAGE_UNKNOWN_OPERATOR << std::endl;
            }
        }
    }
    float CalculatorApplication::divide (float number1, float number2)
    {
        if(number2 == 0)
        {
            std::cerr << CalculatorStrings::ERROR_MESSAGE_DIVIDE_BY_ZERO;
            return(-1);
        }
        else
        {
            float result = number1 / number2;
            return result;
        } 
    }

    int CalculatorApplication::modulus(float number1, float number2)
    {
        int result = (int)number1 % (int)number2;
        return result;
    }
    float CalculatorApplication::multiply (float number1, float number2)
    {
        float result = number1 * number2;
        return result;
    }
    float CalculatorApplication::subtract (float number1, float number2)
    {
        float result = number1 - number2;
        return result;
    }
}