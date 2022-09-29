#ifndef SUBTRACTION_H
#define SUBTRACTION_H

#include <memory>

#include "IMathOperation.h"

class Subtraction : public IMathOperation
{
    public:
        Subtraction(std::unique_ptr<IMathOperation>&& lhs, std::unique_ptr<IMathOperation>&& rhs);

        double calculate() override;
        int    getDepth()  override;

    private:
        std::unique_ptr<IMathOperation> lhs_;
        std::unique_ptr<IMathOperation> rhs_;

        int leftDepth_;
        int rightDepth_;
};

#endif