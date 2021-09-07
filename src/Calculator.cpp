////////////////////////////////////////////////////////////////////////////
/**
 *  @file   Calculator.cpp
 *  @date   Fri April 16 2021
 *  @brief  These are the functions that are used by main.cpp
 */
////////////////////////////////////////////////////////////////////////////

#include "../inc/Calculator.h"
#include "../inc/Messages.h"

namespace calculator
{
    //*************/
    // Calculator public methods /
    ///
    float Calculator::add (float number1, float number2)
    {
        float result = number1 + number2;
        return result;    
    }
    void Calculator::calculate()
    {
        float number1, number2;
        char op;
        std::cout << "Welcome to the Calculator C++ learning project." << std::endl;
        std::cout << "Please enter math problem" << std::endl;
        std::cin >> number1 >> op >>  number2;
        while(1)
        {
            if(std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "You have entered wrong input" << std::endl;
                std::cout << "Please enter the math problem again" << std::endl;
                std::cin >> number1 >> op >> number2;
            }
            if(!std::cin.fail())
            {
                break;
            }
        }
        Calculator calculator;
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
                std::cerr << "unknown operator" << std::endl;
            }
        }
    }
    float Calculator::divide (float number1, float number2)
    {
        if(number2 == 0)
        {
            std::cerr << Messages::DIVIDE_BY_ZERO;
            exit(-1);
        }
        else
        {
            float result = number1 / number2;
            return result;
        } 
    }

    int Calculator::modulus(float number1, float number2)
    {
        int result = (int)number1 % (int)number2;
        return result;
    }
    float Calculator::multiply (float number1, float number2)
    {
        float result = number1 * number2;
        return result;
    }
    float Calculator::subtract (float number1, float number2)
    {
        float result = number1 - number2;
        return result;
    }


}