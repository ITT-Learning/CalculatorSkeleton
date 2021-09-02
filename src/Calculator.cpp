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
    void Calculator::calculator()
    {
        float number1, number2;
        char op;
        std::cout << "Welcome to the Calculator C++ learning project." << std::endl;
        std::cout << "Please enter math problem" << std::endl;
        std::cin >> number1 >> op >>  number2;
        Calculator calc;
        switch(op)
        {
            case '+':
                    calc.add(number1, number2, op);
            break;
            case '*':
                    calc.multiply(number1, number2, op);
                    break;
            case '/':
                    calc.divide(number1, number2,op);
                    break;
            case '-':
                    calc.subtract(number1, number2,op);
                    break;
            case '%':
                    calc.modulus(number1, number2, op);
                    break;    
            default:
                    throw std::runtime_error("unknown operator");
        }
    }

    void Calculator::add (float number1, float number2, char op)
    {
            std::cout << number1 << op << number2 << " = " << number1+number2 << std::endl; 
    }
    void Calculator::multiply (float number1, float number2, char op)
    {
            std::cout << number1 << op << number2 << " = " << number1*number2 << std::endl; 
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
    
    void Calculator::subtract (float number1, float number2, char op)
    {
            std::cout << number1 << op << number2 << " = " << number1-number2 << std::endl; 
    }
    void Calculator::modulus(float number1, float number2, char op)
    {
            std::cout << number1 << op << number2 << " = " << (int)number1%(int)number2 << std:: endl;
    }
}