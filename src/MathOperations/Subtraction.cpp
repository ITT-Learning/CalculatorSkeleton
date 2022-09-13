#include "Subtraction.h"

Subtraction::Subtraction(IMathOperation* lhs, IMathOperation* rhs)
{
    lhs_ = lhs;
    rhs_ = rhs;
};



Subtraction::~Subtraction()
{
    delete lhs_;
    delete rhs_;
};



double Subtraction::calculate()
{
    return lhs_->calculate() - rhs_->calculate();
};