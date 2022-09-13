#ifndef DIVISION_H
#define DIVISION_H

#include "IMathOperation.h"

class Division : public IMathOperation
{
    public:
        Division(IMathOperation* lhs, IMathOperation* rhs);
        ~Division();

        double calculate() override;

    private:
        IMathOperation* lhs_;
        IMathOperation* rhs_;
};

#endif