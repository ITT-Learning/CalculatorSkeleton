/**
 * @file DivideCalculator.cpp
 * @brief Functions that support main.cpp
 * @version 0.1
 * @date 2021-10-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "DivideCalculator.h"

namespace calculator
{
    DivideCalculator::DivideCalculator(float a, float b)
    {
        firstNumber_ = a; 
        secondNumber_ = b;
        op_ = '/';
    }
    float DivideCalculator::getResult()
    {
        if(secondNumber_ == 0) //if second number = 0, output error message
        {
            std::cerr << CalculatorStrings::ERROR_MESSAGE_DIVIDE_BY_ZERO << std::endl;
            return -1;
        }
        else
        {
            return firstNumber_ / secondNumber_; //else, return first variable divided by the second
        }
        
    }
}