#ifndef CONSTANT_H
#define CONSTANT_H

#include "IMathOperation.h"

class Constant : IMathOperation
{
    private:
        double m_value;
    
    public:
        Constant(double p_value);
        
        virtual double calculate();
};

#endif