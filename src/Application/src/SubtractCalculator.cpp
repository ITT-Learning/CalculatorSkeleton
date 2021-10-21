/**
 * @file SubtractCalculator.cpp
 * @brief Funtions that support main.cpp
 * @version 0.1
 * @date 2021-10-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "SubtractCalculator.h"


namespace calculator
{
    SubtractCalculator::SubtractCalculator(float a, float b)
    {
        firstNumber_ = a; 
        secondNumber_ = b;
        op_ = '-';
    }
    float SubtractCalculator::getResult()
    {
        return firstNumber_ - secondNumber_; //returns second variable subtracted by first variable 
    }
}