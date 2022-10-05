#include "CalculatorService.h"

#include <string>
#include <unordered_map>
#include <vector>

#include "MathExpression.h"
#include "Result.h"

const Calculator CalculatorService::calculator_ = Calculator(std::make_unique<FourOperationFactory>());



Result<std::string> CalculatorService::calculate(std::string equation, std::unordered_map<std::string, double> variables)
{
    MathExpression expression(equation);
    if (expression.getRawEquation().empty())
    {
        return Result<std::string>("", false, "No valid equation found.\n");
    }

    if (!variables.empty())
    {
        for (auto it = variables.cbegin(); it != variables.cend(); it++)
        {
            expression.setVariableValue(it->first, it->second);
        }
    }

    Result<std::vector<std::string>> infixVectorResult = expression.getPopulatedEquation();
    if (!infixVectorResult.isValid())
    {
        return Result<std::string>("", false, "Error: " + infixVectorResult.getError());
    }

    Result<double> calculationResult = calculator_.calculateResult(infixVectorResult.getResult());
    if (!calculationResult.isValid())
    {
        return Result<std::string>("", false, "Error: " + calculationResult.getError());
    }

    return Result<std::string>(std::to_string(calculationResult.getResult()));
};