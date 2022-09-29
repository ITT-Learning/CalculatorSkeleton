#include "Constant.h"



Constant::Constant(double value)
{
    value_ = value;
};



double Constant::calculate()
{
    return value_;
};

int Constant::getDepth()
{
    return 0;
}