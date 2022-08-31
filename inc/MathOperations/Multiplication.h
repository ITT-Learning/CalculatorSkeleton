#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include "IMathOperation.h"

class Multiplication : public IMathOperation
{
    private:
        IMathOperation* lhs;
        IMathOperation* rhs;

    public:
        Multiplication(IMathOperation* p_lhs, IMathOperation* p_rhs);
        ~Multiplication();

        virtual double calculate();
};

#endif