/**
 * @file CalculatorW2.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-07-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <float.h>
#include "CalculatorW2.h"

namespace calculatorw2
{
    CalculatorW2::CalculatorW2(): error_(nullptr)
    {

    }
    
    CalculatorW2::~CalculatorW2() {}
    
    const char* CalculatorW2::getError()
    {
        return error_;
    }

    double CalculatorW2::calculate(double left, double right, char operation)
    {
        double result = 0;
        
        switch (operation)
        {
            case '+':
            {
                result = add(left, right);
                break;
            }
            case '-':
            {
                result = subtract(left, right);
                break;
            }
            case '*':
            {
                result = multiply(left, right);
                break;
            }
            case '/':
            {
                result = divide(left, right);
                break;
            }
            default:
            {
                error_ = unknownOperationError;
                break;
            }
        }

        return result;
    }

    double CalculatorW2::add(double left, double right)
    {
        error_ = nullptr;
        return left + right;
    }

    double CalculatorW2::subtract(double left, double right)
    {
        error_ = nullptr;
        return left - right;
    }

    double CalculatorW2::multiply(double left, double right)
    {
        error_ = nullptr;
        return left * right;
    }

    double CalculatorW2::divide(double left, double right)
    {
        error_ = nullptr;
        double result;

        if (right == 0 || right == 0.0)
        {
            error_ = divideByZeroError;
            result = DBL_MAX_10_EXP;
        }
        else
        {
            result = left / right;
        }

        return result;
    }

} // namespace calculatorw2
