
////////////////////////////////////////////////////////////////////////////
/**
 *  @file   DivideCalculator.cpp
 *  @date   Fri April 16 2021
 *  @brief  Funtions that support main.cpp
 */
////////////////////////////////////////////////////////////////////////////

#include <iostream>

#include "DivideCalculator.h"
#include "CalculatorStrings.h"

namespace calculator
{
    DivideCalculator::DivideCalculator(int leftTerm, int rightTerm)
    {
        leftTerm_ = leftTerm;
        rightTerm_ = rightTerm;
        if(rightTerm == 0)
        {
            std::cerr << CalculatorStrings::ERROR_MESSAGE << CalculatorStrings::ERROR_MESSAGE_DIVIDE_BY_ZERO << std::endl;
        }
    }
    
    int DivideCalculator::getResult() 
    {
        if(rightTerm_ == 0)
        {
            return -1;
        }
        return leftTerm_ / rightTerm_;
    }
    
    char DivideCalculator::getOperation() 
    {
        return operation;
    }
}