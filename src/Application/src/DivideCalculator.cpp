/**
 * @file DivideCalculator.cpp
 * @brief Funtions that support main.cpp
 * @version 0.1
 * @date 2021-10-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "../inc/DivideCalculator.h"

namespace calculator
{
    DivideCalculator::DivideCalculator(float a, float b)
    {
        first_Number = a; 
        second_Number = b;
        op = '/';
    }
    float DivideCalculator::getResult()
    {
        if(second_Number == 0) //if second number = 0, output error message
        {
            std::cerr << CalculatorStrings::ERROR_MESSAGE_DIVIDE_BY_ZERO<< std::endl;
            return -1;
        }
        else
        {
            return first_Number / second_Number; //else, return first variable divided by the second
        }
        
    }
}