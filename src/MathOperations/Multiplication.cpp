#include "Multiplication.h"

#include <memory>

Multiplication::Multiplication(std::unique_ptr<IMathOperation>&& lhs, std::unique_ptr<IMathOperation>&& rhs)
{
    lhs_ = std::move(lhs);
    rhs_ = std::move(rhs);
};



double Multiplication::calculate()
{
    return lhs_->calculate() * rhs_->calculate();
};