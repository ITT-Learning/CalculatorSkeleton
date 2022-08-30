#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include "IMathOperation.h"

class Multiplication : IMathOperation
{
    private:
        IMathOperation* lhs;
        IMathOperation* rhs;

    public:
        Multiplication(IMathOperation* p_lhs, IMathOperation* p_rhs);

        virtual double calculate();
};

#endif