////////////////////////////////////////////////////////////////////////////
/**
 *  @file   Calculator.cpp
 *  @date   Fri April 16 2021
 *  @brief  These are the functions that are used by main.cpp
 */
////////////////////////////////////////////////////////////////////////////

#include "../inc/Calculator.h"

namespace calculator
{
    //*************/
    // Calculator public methods /
    ///
    void Calculator::add (float number1, float number2, char op)
    {
            std::cout << number1 << op << number2 << " = " << number1+number2 << std::endl; 
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
                calculator.add(number1, number2, op);
                break;
            }
            case '*':
            {
                calculator.multiply(number1, number2, op);
                break;
            }
            case '/':
            {
                calculator.divide(number1, number2,op);
                break;
            }
            case '-':
            {
                calculator.subtract(number1, number2,op);
                break;
            }
            case '%':
            {
                calculator.modulus(number1, number2, op);
                break;
            }
            default:
            {
                throw std::runtime_error("unknown operator");
            }
        }
    }
    void Calculator::divide (float number1, float number2, char op)
    {
        if(number2 == 0)
        {
            throw std::runtime_error("Math error: Attempted to divide by Zero\n");
        }
        else
            std::cout << number1 << op << number2 << " = " << number1/number2 << std::endl; 
    }
    void Calculator::modulus(float number1, float number2, char op)
    {
            std::cout << number1 << op << number2 << " = " << (int)number1%(int)number2 << std:: endl;
    }
    void Calculator::multiply (float number1, float number2, char op)
    {
            std::cout << number1 << op << number2 << " = " << number1*number2 << std::endl; 
    }
    void Calculator::subtract (float number1, float number2, char op)
    {
            std::cout << number1 << op << number2 << " = " << number1-number2 << std::endl; 
    }

}