#include "Subtraction.h"

Subtraction::Subtraction(IMathOperation* p_lhs, IMathOperation* p_rhs)
{
    lhs = p_lhs;
    rhs = p_rhs;
};

double Subtraction::calculate()
{
    return lhs->calculate() - rhs->calculate();
};