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
#include <vector>
#include <memory>

#include "MathExpression.h"
#include "IMathOperation.h"
#include "IOperationFactory.h"
#include "Result.h"

class Calculator
{
    public:
        Calculator(std::unique_ptr<IOperationFactory>&& factory);

        Result<double> calculateResult(std::vector<std::string> infixVector) const;

    private:
        std::unique_ptr<IOperationFactory> factory_;

        Result<std::unique_ptr<IMathOperation>> extractOperation(std::stack<std::string>& postfixStack) const;
        static Result<std::stack<std::string>>  infixToPostfix(std::vector<std::string> infixString);

        static Result<bool> plusMinusInfixCase(
            std::vector<std::string>::const_iterator &it,
            std::stack<std::string>                  &outputStack,
            std::stack<char>                         &operatorStack,
            bool                                     previousValueIsAParenthesis
        );
};

#endif