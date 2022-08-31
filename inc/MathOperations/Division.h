#ifndef DIVISION_H
#define DIVISION_H

#include "IMathOperation.h"

class Division : public IMathOperation
{
    private:
        IMathOperation* lhs;
        IMathOperation* rhs;

    public:
        Division(IMathOperation* p_lhs, IMathOperation* p_rhs);
        ~Division();

        virtual double calculate();
};

#endif