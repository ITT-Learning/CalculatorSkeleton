#include "Constant.h"

Constant::Constant(double value)
{
    value_ = value;
};



double Constant::calculate() const
{
    return value_;
};