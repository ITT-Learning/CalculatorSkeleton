#include "Multiplication.h"

#include <memory>

Multiplication::Multiplication(IMathOperation* lhs, IMathOperation* rhs)
{
    lhs_ = std::unique_ptr<IMathOperation>(lhs);
    rhs_ = std::unique_ptr<IMathOperation>(rhs);
};



double Multiplication::calculate()
{
    return lhs_->calculate() * rhs_->calculate();
};