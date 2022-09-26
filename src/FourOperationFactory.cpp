#include "FourOperationFactory.h"

#include <memory.h>
#include <algorithm>

#include "Constant.h"
#include "Addition.h"
#include "Subtraction.h"
#include "Multiplication.h"
#include "Division.h"
#include "NotANumber.h"



std::unique_ptr<IMathOperation> FourOperationFactory::getOperationFor(
    std::string operatorName,
    std::unique_ptr<IMathOperation>&& lhs,
    std::unique_ptr<IMathOperation>&& rhs) const
{
    if (!lhs || !rhs || operatorName.empty())
    {
        return std::make_unique<NotANumber>();
    }

    if (operatorName == "+")
    {
        return std::make_unique<Addition>(std::move(lhs), std::move(rhs));
    }
    if (operatorName == "-")
    {
        return std::make_unique<Subtraction>(std::move(lhs), std::move(rhs));
    }
    if (operatorName == "*")
    {
        return std::make_unique<Multiplication>(std::move(lhs), std::move(rhs));
    }
    if (operatorName == "/")
    {
        return std::make_unique<Division>(std::move(lhs), std::move(rhs));
    }
    
    return std::make_unique<NotANumber>();
};



std::unique_ptr<IMathOperation> FourOperationFactory::getConstantFor(double constantValue) const
{
    return std::make_unique<Constant>(constantValue);
};