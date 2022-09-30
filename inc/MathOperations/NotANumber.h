#ifndef NOT_A_NUMBER_H
#define NOT_A_NUMBER_H

#include <cmath>

#include "IMathOperation.h"

class NotANumber : public IMathOperation
{
    public:
        inline double calculate() const override { return nan(""); };
};

#endif