#include "Division.h"

Division::Division(IMathOperation* lhs, IMathOperation* rhs)
{
    lhs_ = lhs;
    rhs_ = rhs;
};



Division::~Division()
{
    delete lhs_;
    delete rhs_;
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