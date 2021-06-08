
////////////////////////////////////////////////////////////////////////////
/**
 *  @file   AddCalculator.cpp
 *  @date   Fri April 16 2021
 *  @brief  Funtions that support main.cpp
 */
////////////////////////////////////////////////////////////////////////////

#include "AddCalculator.h"
#include "CalculatorStrings.h"

namespace calculator
{
    AddCalculator::AddCalculator(int leftTerm, int rightTerm)
    {
        leftTerm_ = leftTerm;
        rightTerm_ = rightTerm;
    }
    
    int AddCalculator::getResult() 
    {
        return leftTerm_ + rightTerm_;
    }
    
    char AddCalculator::getOperation() 
    {
        return operation;
    }
}