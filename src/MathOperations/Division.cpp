#include "Division.h"

#include <memory>

Division::Division(IMathOperation* lhs, IMathOperation* rhs)
{
    lhs_ = std::unique_ptr<IMathOperation>(lhs);
    rhs_ = std::unique_ptr<IMathOperation>(rhs);
};



double Division::calculate()
{
    double rhsResult = rhs_->calculate();
    if (rhsResult != 0)
    {
        return lhs_->calculate() / rhsResult;
    }
    else
    {
        return 0;
    }
};