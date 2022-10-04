#ifndef SERVICES_CALCULATOR_SERVICE_H
#define SERVICES_CALCULATOR_SERVICE_H

#include <string>
#include <memory>

#include "Calculator.h"
#include "FourOperationFactory.h"
#include "Result.h"


class CalculatorService
{
    public:
        static Result<std::string> calculate(std::string equation);

    private:
        CalculatorService() {};
        static const Calculator calculator_;
};


#endif