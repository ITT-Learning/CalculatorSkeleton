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

class Calculator
{
    public:
        Calculator(std::unique_ptr<IOperationFactory>&& factory);

        double                calculate(std::string equationString);
        static std::string    sanitizeString(std::string unsanitizedString);

    private:
        std::unique_ptr<IOperationFactory> factory_;

        std::unique_ptr<IMathOperation>     extractOperation(std::stack<std::string>& postfixStack);
        static std::stack<std::string>      infixToPostfix(std::string infixString);
};

#endif