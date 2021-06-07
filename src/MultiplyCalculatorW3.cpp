
////////////////////////////////////////////////////////////////////////////
/**
 *  @file   MultiplyCalculatorW3.cpp
 *  @date   Fri April 16 2021
 *  @brief  Funtions that support main.cpp
 */
////////////////////////////////////////////////////////////////////////////

#include "MultiplyCalculatorW3.h"

namespace calculator
{
    MultiplyCalculatorW3::MultiplyCalculatorW3(int leftTerm, int rightTerm)
    {
        leftTerm_ = leftTerm;
        rightTerm_ = rightTerm;
    }
    
    int MultiplyCalculatorW3::getResult() 
    {
        return leftTerm_ * rightTerm_;
    }
    
    char MultiplyCalculatorW3::getOperation() 
    {
        return operation;
    }
}