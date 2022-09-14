#include "Subtraction.h"

Subtraction::Subtraction(IMathOperation* lhs, IMathOperation* rhs)
{
    lhs_ = std::unique_ptr<IMathOperation>(lhs);
    rhs_ = std::unique_ptr<IMathOperation>(rhs);
};



double Subtraction::calculate()
{
    return lhs_->calculate() - rhs_->calculate();
};