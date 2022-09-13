#include "Addition.h"

Addition::Addition(IMathOperation* lhs, IMathOperation* rhs)
{
    lhs_ = lhs;
    rhs_ = rhs;
};



Addition::~Addition()
{
    delete lhs_;
    delete rhs_;
};



double Addition::calculate()
{
    return lhs_->calculate() + rhs_->calculate();
};