#ifndef ADDITION_H
#define ADDITION_H

#include "IMathOperation.h"

class Addition : IMathOperation
{
    private:
        IMathOperation* lhs;
        IMathOperation* rhs;
    
    public:
        Addition(IMathOperation* p_lhs, IMathOperation* p_rhs);

        virtual double calculate();
};

#endif