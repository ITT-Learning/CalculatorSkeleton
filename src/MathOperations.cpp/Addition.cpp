#include "Addition.h"

Addition::Addition(IMathOperation* p_lhs, IMathOperation* p_rhs)
{
    lhs = p_lhs;
    rhs = p_rhs;
};

Addition::~Addition()
{
    delete lhs;
    delete rhs;
}

double Addition::calculate()
{
    return lhs->calculate() + rhs->calculate();
};