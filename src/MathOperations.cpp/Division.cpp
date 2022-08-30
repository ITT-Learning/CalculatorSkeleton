#include "Division.h"

Division::Division(IMathOperation* p_lhs, IMathOperation* p_rhs)
{
    lhs = p_lhs;
    rhs = p_rhs;
};

double Division::calculate()
{
    double rhsResult = rhs->calculate();
    if(rhsResult != 0)
    {
        return lhs->calculate() / rhsResult;
    }
    else
    {
        return 0;
    }
};