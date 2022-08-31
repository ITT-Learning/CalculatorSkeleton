#ifndef SUBTRACTION_H
#define SUBTRACTION_H

#include "IMathOperation.h"

class Subtraction : public IMathOperation
{
    private:
        IMathOperation* lhs;
        IMathOperation* rhs;

    public:
        Subtraction(IMathOperation* p_lhs, IMathOperation* p_rhs);
        ~Subtraction();

        virtual double calculate();
};

#endif