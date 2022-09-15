#ifndef DIVISION_H
#define DIVISION_H

#include <memory>

#include "IMathOperation.h"

class Division : public IMathOperation
{
    public:
        Division(std::unique_ptr<IMathOperation>&& lhs, std::unique_ptr<IMathOperation>&& rhs);

        double calculate() override;

    private:
        std::unique_ptr<IMathOperation> lhs_;
        std::unique_ptr<IMathOperation> rhs_;
};

#endif