#ifndef NOT_A_NUMBER_H
#define NOT_A_NUMBER_H

#include <cmath>

#include "IMathOperation.h"

class NotANumber : public IMathOperation
{
    public:
        inline double calculate() override { return nan(""); };
        inline int    getDepth()  override { return 0; };
};

#endif