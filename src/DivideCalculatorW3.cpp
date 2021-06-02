
////////////////////////////////////////////////////////////////////////////
/**
 *  @file   DivideCalculatorW3.cpp
 *  @date   Fri April 16 2021
 *  @brief  Funtions that support main.cpp
 */
////////////////////////////////////////////////////////////////////////////

#include <iostream>

#include "DivideCalculatorW3.h"
#include "CalculatorStrings.h"

namespace calculator
{
    DivideCalculatorW3::DivideCalculatorW3(int leftTerm, int rightTerm)
    {
        leftTerm_ = leftTerm;
        rightTerm_ = rightTerm;
        if(rightTerm == 0)
        {
            std::cerr << CalculatorStrings::ERROR_MESSAGE << CalculatorStrings::ERROR_MESSAGE_DIVIDE_BY_ZERO << std::endl;
        }
    }
    
    int DivideCalculatorW3::getResult() 
    {
        if(rightTerm_ == 0)
        {
            return -1;
        }
        return leftTerm_ / rightTerm_;
    }
    
    char DivideCalculatorW3::getOperation() 
    {
        return operation;
    }
}