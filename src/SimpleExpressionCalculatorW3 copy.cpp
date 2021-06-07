
////////////////////////////////////////////////////////////////////////////
/**
 *  @file   SimpleExpressionCalculatorW3.cpp
 *  @date   Fri April 16 2021
 *  @brief  Base class for simple arithmitic calculators with exactly two terms.
 */
////////////////////////////////////////////////////////////////////////////

#include "CalculatorStrings.h"
#include "SimpleExpressionCalculatorW3.h"

namespace calculator
{
    std::string SimpleExpressionCalculatorW3::getExpression() 
    {
        return std::to_string(leftTerm_) + CalculatorStrings::SPACE + getOperation() + CalculatorStrings::SPACE + std::to_string(rightTerm_);
    }
    
    std::string SimpleExpressionCalculatorW3::toString() 
    {
        return getExpression() + CalculatorStrings::EQUAL + std::to_string(getResult());
    }


}