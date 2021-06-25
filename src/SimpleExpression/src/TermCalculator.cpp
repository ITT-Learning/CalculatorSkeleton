////////////////////////////////////////////////////////////////////////////
/**
 *  @file   TermCalculator.cpp
 *  @date   Fri, June 18 2021
 *  @brief  Calculator that represents a single term
 */
////////////////////////////////////////////////////////////////////////////

#include "TermCalculator.h"

namespace calculator {
    TermCalculator::TermCalculator(int term)
            :term_(term)
    {}

    std::string TermCalculator::getExpression() const
    {
        return std::to_string(term_);
    }

    int TermCalculator::getResult() const
    {
        return term_;
    }

    std::string TermCalculator::toString() const
    {
        return std::to_string(term_);
    }
}
