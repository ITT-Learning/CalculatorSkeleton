///////////////////////////////////////////////////////////////////////////////
/**
 * @file  Calculator.h
 * @date  Fri, 16 April 2021
 * @brief 
 * 
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include <stack>
#include <memory>

#include "IMathOperation.h"
#include "IOperationFactory.h"
#include "Result.h"
#include "PostfixResult.h"

class Calculator
{
    public:
        Calculator(std::unique_ptr<IOperationFactory>&& factory);

        Result<double>        calculateResult(std::string equationString)   const;
        static std::string    sanitizeString(std::string unsanitizedString);

    private:
        std::unique_ptr<IOperationFactory> factory_;

        Result<std::unique_ptr<IMathOperation>>  extractOperation(std::stack<std::string>& postfixStack) const;
        static Result<std::stack<std::string>>   infixToPostfix(std::string infixString);
};

#endif