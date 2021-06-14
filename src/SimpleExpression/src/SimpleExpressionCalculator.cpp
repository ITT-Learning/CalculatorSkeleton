
////////////////////////////////////////////////////////////////////////////
/**
 *  @file   SimpleExpressionCalculator.cpp
 *  @date   Fri April 16 2021
 *  @brief  Base class for simple arithmitic calculators with exactly two terms.
 */
////////////////////////////////////////////////////////////////////////////

#include "CalculatorStrings.h"
#include "SimpleExpressionCalculator.h"

namespace calculator
{
    std::string SimpleExpressionCalculator::getExpression() const
    {
        return std::to_string(leftTerm_) + CalculatorStrings::SPACE + getOperation() + CalculatorStrings::SPACE + std::to_string(rightTerm_);
    }
    
    std::string SimpleExpressionCalculator::toString() const
    {
        return getExpression() + CalculatorStrings::EQUAL + std::to_string(getResult());
    }


}