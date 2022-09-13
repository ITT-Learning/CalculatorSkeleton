#include "Multiplication.h"

Multiplication::Multiplication(IMathOperation* lhs, IMathOperation* rhs)
{
    lhs_ = lhs;
    rhs_ = rhs;
};



Multiplication::~Multiplication()
{
    delete lhs_;
    delete rhs_;
};



double Multiplication::calculate()
{
    return lhs_->calculate() * rhs_->calculate();
};