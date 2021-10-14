/**
 * @file MultiplyCalculator.cpp
 * @brief Funtions that support main.cpp
 * @version 0.1
 * @date 2021-10-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<memory>

#include "../inc/MultiplyCalculator.h"


namespace calculator
{
    MultiplyCalculator::MultiplyCalculator(float a, float b)
    {
        first_Number = a; 
        second_Number = b;
        op = '*';
    }
    float MultiplyCalculator::getResult()
    {
        return first_Number * second_Number; //return variables multiplied by each other 
    }
}