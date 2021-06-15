////////////////////////////////////////////////////////////////////////////
/**
 *  @file   TermCalculator.cpp
 *  @date   Fri, June 18 2021
 *  @brief  Calcualtor that represents a single term
 */
////////////////////////////////////////////////////////////////////////////

#include "TermCalculator.h"

calculator::TermCalculator::TermCalculator(int term)
        :term_(term)
{}

std::string calculator::TermCalculator::getExpression() const
{
    return std::to_string(term_);
}

int calculator::TermCalculator::getResult() const
{
    return term_;
}

std::string calculator::TermCalculator::toString() const
{
    return std::to_string(term_);
}
