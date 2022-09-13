#ifndef CONSTANT_H
#define CONSTANT_H

#include "IMathOperation.h"

class Constant : public IMathOperation
{
    public:
        Constant(double value);
        
        double calculate() override;

    private:
        double value_;
};

#endif