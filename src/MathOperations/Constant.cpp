#include "Constant.h"

Constant::Constant(double p_value)
{
    m_value = p_value;
};

double Constant::calculate()
{
    return m_value;
};