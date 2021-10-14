/**
 * @file AddCalculator.cpp
 * @brief Funtions that support main.cpp
 * @version 0.1
 * @date 2021-10-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "AddCalculator.h"

namespace calculator
{
    //Constructor places first and second inputted numbers into protected variables
    AddCalculator::AddCalculator(float a, float b)
    {
        first_Number = a; 
        second_Number = b;
        op = '+';
    }
    //composes the result of the variables added together
    float AddCalculator::getResult()
    {
        return first_Number + second_Number;
    }
}