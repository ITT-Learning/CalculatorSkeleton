#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include "IMathOperation.h"

class Multiplication : public IMathOperation
{
    public:
        Multiplication(IMathOperation* lhs, IMathOperation* rhs);
        ~Multiplication();

        double calculate() override;

    private:
        IMathOperation* lhs_;
        IMathOperation* rhs_;
};

#endif