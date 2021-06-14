
////////////////////////////////////////////////////////////////////////////
/**
 *  @file   MultiplyCalculator.cpp
 *  @date   Fri April 16 2021
 *  @brief  Funtions that support main.cpp
 */
////////////////////////////////////////////////////////////////////////////

#include "MultiplyCalculator.h"

namespace calculator
{
    MultiplyCalculator::MultiplyCalculator(int leftTerm, int rightTerm)
    {
        leftTerm_ = leftTerm;
        rightTerm_ = rightTerm;
    }
    
    int MultiplyCalculator::getResult() const
    {
        return leftTerm_ * rightTerm_;
    }
    
    char MultiplyCalculator::getOperation() const
    {
        return operation;
    }
}