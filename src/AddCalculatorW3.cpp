
////////////////////////////////////////////////////////////////////////////
/**
 *  @file   AddCalculatorW3.cpp
 *  @date   Fri April 16 2021
 *  @brief  Funtions that support main.cpp
 */
////////////////////////////////////////////////////////////////////////////

#include "AddCalculatorW3.h"
#include "CalculatorStrings.h"

namespace calculator
{
    AddCalculatorW3::AddCalculatorW3(int leftTerm, int rightTerm)
    {
        leftTerm_ = leftTerm;
        rightTerm_ = rightTerm;
    }
    
    int AddCalculatorW3::getResult() 
    {
        return leftTerm_ + rightTerm_;
    }
    
    char AddCalculatorW3::getOperation() 
    {
        return operation;
    }
}