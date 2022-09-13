#ifndef SUBTRACTION_H
#define SUBTRACTION_H

#include "IMathOperation.h"

class Subtraction : public IMathOperation
{
    public:
        Subtraction(IMathOperation* lhs, IMathOperation* rhs);
        ~Subtraction();

        double calculate() override;

    private:
        IMathOperation* lhs_;
        IMathOperation* rhs_;
};

#endif