#ifndef FOUR_OPERATION_FACTORY_H
#define FOUR_OPERATION_FACTORY_H

#include <memory>

#include "IOperationFactory.h"
#include "IMathOperation.h"

class FourOperationFactory : public IOperationFactory
{
    public:
        std::unique_ptr<IMathOperation> getOperationFor(
            std::string operatorName,
            std::unique_ptr<IMathOperation>&& lhs,
            std::unique_ptr<IMathOperation>&& rhs
        ) override;

        std::unique_ptr<IMathOperation> getOperationFor(double constantValue) override;
};

#endif