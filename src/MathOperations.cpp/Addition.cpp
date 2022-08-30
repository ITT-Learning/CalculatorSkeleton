#include "Addition.h"

Addition::Addition(IMathOperation* p_lhs, IMathOperation* p_rhs)
{
    lhs = p_lhs;
    rhs = p_rhs;
};

double Addition::calculate()
{
    return lhs->calculate() + rhs->calculate();
};