#include "Subtraction.h"

Subtraction::Subtraction(IMathOperation* p_lhs, IMathOperation* p_rhs)
{
    lhs = p_lhs;
    rhs = p_rhs;
};

Subtraction::~Subtraction()
{
    delete lhs;
    delete rhs;
}

double Subtraction::calculate()
{
    return lhs->calculate() - rhs->calculate();
};