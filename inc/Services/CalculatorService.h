#ifndef SERVICES_CALCULATOR_SERVICE_H
#define SERVICES_CALCULATOR_SERVICE_H

#include <string>
#include <memory>
#include <unordered_map>

#include "Calculator.h"
#include "FourOperationFactory.h"
#include "Result.h"


class CalculatorService
{
    public:
        static Result<std::string> calculate(std::string equation, std::unordered_map<std::string, double> variables);

    private:
        CalculatorService() {};
        static const Calculator calculator_;
};


#endif