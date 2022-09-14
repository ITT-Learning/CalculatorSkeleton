#include "Addition.h"

#include <memory>

Addition::Addition(IMathOperation* lhs, IMathOperation* rhs)
{
    lhs_ = std::unique_ptr<IMathOperation>(lhs);
    rhs_ = std::unique_ptr<IMathOperation>(rhs);
};



double Addition::calculate()
{
    return lhs_->calculate() + rhs_->calculate();
};