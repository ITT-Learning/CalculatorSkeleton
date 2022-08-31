#include "Multiplication.h"

Multiplication::Multiplication(IMathOperation* p_lhs, IMathOperation* p_rhs)
{
    lhs = p_lhs;
    rhs = p_rhs;
};

Multiplication::~Multiplication()
{
    delete lhs;
    delete rhs;
}

double Multiplication::calculate()
{
    return lhs->calculate() * rhs->calculate();
};