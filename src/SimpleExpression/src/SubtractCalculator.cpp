
////////////////////////////////////////////////////////////////////////////
/**
 *  @file   SubtractCalculator.cpp
 *  @date   Fri April 16 2021
 *  @brief  Funtions that support main.cpp
 */
////////////////////////////////////////////////////////////////////////////

#include "SubtractCalculator.h"

namespace calculator
{
    SubtractCalculator::SubtractCalculator(int leftTerm, int rightTerm)
    {
        leftTerm_ = leftTerm;
        rightTerm_ = rightTerm;
    }
    
    int SubtractCalculator::getResult() const
    {
        return leftTerm_ - rightTerm_;
    }
    
    char SubtractCalculator::getOperation() const
    {
        return operation;
    }
}