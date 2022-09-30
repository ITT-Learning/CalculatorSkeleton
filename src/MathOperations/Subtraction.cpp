#include "Subtraction.h"

Subtraction::Subtraction(std::unique_ptr<IMathOperation>&& lhs, std::unique_ptr<IMathOperation>&& rhs)
{
    lhs_ = std::move(lhs);
    rhs_ = std::move(rhs);
};



double Subtraction::calculate() const
{
    return lhs_->calculate() - rhs_->calculate();
};