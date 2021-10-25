/**
 * @file MultiplyCalculator.cpp
 * @brief Funtions that support main.cpp
 * @version 0.1
 * @date 2021-10-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "MultiplyCalculator.h"


namespace calculator
{
    MultiplyCalculator::MultiplyCalculator(float a, float b)
    {
        firstNumber_ = a; 
        secondNumber_ = b;
        op_ = '*';
    }
    float MultiplyCalculator::getResult()
    {
        return firstNumber_ * secondNumber_; //return variables multiplied by each other 
    }
}