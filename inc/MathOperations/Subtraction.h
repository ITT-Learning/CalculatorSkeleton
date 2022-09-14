#ifndef SUBTRACTION_H
#define SUBTRACTION_H

#include <memory>

#include "IMathOperation.h"

class Subtraction : public IMathOperation
{
    public:
        Subtraction(IMathOperation* lhs, IMathOperation* rhs);

        double calculate() override;

    private:
        std::unique_ptr<IMathOperation> lhs_;
        std::unique_ptr<IMathOperation> rhs_;
};

#endif