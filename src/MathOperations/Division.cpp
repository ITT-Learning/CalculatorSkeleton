#include "Division.h"

#include <cmath>
#include <memory>

Division::Division(std::unique_ptr<IMathOperation>&& lhs, std::unique_ptr<IMathOperation>&& rhs)
{
    lhs_ = std::move(lhs);
    rhs_ = std::move(rhs);
};



double Division::calculate() const
{
    double rhsResult = rhs_->calculate();
    if (rhsResult != 0)
    {
        return lhs_->calculate() / rhsResult;
    }
    else
    {
        return nan("");
    }
};