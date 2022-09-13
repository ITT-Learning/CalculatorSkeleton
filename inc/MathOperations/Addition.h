#ifndef ADDITION_H
#define ADDITION_H

#include "IMathOperation.h"

class Addition : public IMathOperation
{
    public:
        Addition(IMathOperation* lhs, IMathOperation* rhs);
        ~Addition();

        double calculate() override;

    private:
        IMathOperation* lhs_;
        IMathOperation* rhs_;
};

#endif