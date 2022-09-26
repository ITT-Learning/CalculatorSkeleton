#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include <memory>

#include "IMathOperation.h"

class Multiplication : public IMathOperation
{
    public:
        Multiplication(std::unique_ptr<IMathOperation>&& lhs, std::unique_ptr<IMathOperation>&& rhs);

        double calculate() override;

    private:
        std::unique_ptr<IMathOperation> lhs_;
        std::unique_ptr<IMathOperation> rhs_;
};

#endif