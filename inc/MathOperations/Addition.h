#ifndef ADDITION_H
#define ADDITION_H

#include <memory>

#include "IMathOperation.h"

class Addition : public IMathOperation
{
    public:
        Addition(IMathOperation* lhs, IMathOperation* rhs);

        double calculate() override;

    private:
        std::unique_ptr<IMathOperation> lhs_;
        std::unique_ptr<IMathOperation> rhs_;
};

#endif