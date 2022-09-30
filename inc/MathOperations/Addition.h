#ifndef ADDITION_H
#define ADDITION_H

#include <memory>

#include "IMathOperation.h"

class Addition : public IMathOperation
{
    public:
        Addition(std::unique_ptr<IMathOperation>&& lhs, std::unique_ptr<IMathOperation>&& rhs);

        double calculate() const override;

    private:
        std::unique_ptr<IMathOperation> lhs_;
        std::unique_ptr<IMathOperation> rhs_;
};

#endif