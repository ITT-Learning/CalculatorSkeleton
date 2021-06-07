
////////////////////////////////////////////////////////////////////////////
/**
 *  @file   SubtractCalculatorW3.cpp
 *  @date   Fri April 16 2021
 *  @brief  Funtions that support main.cpp
 */
////////////////////////////////////////////////////////////////////////////

#include "SubtractCalculatorW3.h"

namespace calculator
{
    SubtractCalculatorW3::SubtractCalculatorW3(int leftTerm, int rightTerm)
    {
        leftTerm_ = leftTerm;
        rightTerm_ = rightTerm;
    }
    
    int SubtractCalculatorW3::getResult() 
    {
        return leftTerm_ - rightTerm_;
    }
    
    char SubtractCalculatorW3::getOperation() 
    {
        return operation;
    }
}