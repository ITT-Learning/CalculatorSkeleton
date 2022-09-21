#ifndef I_OPERATION_FACTORY_H
#define I_OPERATION_FACTORY_H

#include <string>
#include <memory>

#include "IMathOperation.h"

class IOperationFactory
{
    public:
        virtual ~IOperationFactory() {};

        virtual std::unique_ptr<IMathOperation> getOperationFor(
            std::string operatorName,
            std::unique_ptr<IMathOperation>&& lhs,
            std::unique_ptr<IMathOperation>&& rhs
        ) const = 0;

        virtual std::unique_ptr<IMathOperation> getConstantFor(double constantValue) const = 0;
};

#endif