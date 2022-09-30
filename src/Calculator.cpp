////////////////////////////////////////////////////////////////////////////
/**
 *  @file   Calculator.cpp
 *  @date   Fri April 16 2021
 *  @brief  Funtions that support main.cpp
 */
////////////////////////////////////////////////////////////////////////////

#include "Calculator.h"

#include <cctype>
#include <cmath>
#include <stack>
#include <vector>
#include <memory>

#include "MathExpression.h"
#include "Result.h"
#include "IOperationFactory.h"
#include "Constant.h"
#include "Addition.h"
#include "Subtraction.h"
#include "Multiplication.h"
#include "Division.h"
#include "NotANumber.h"



Calculator::Calculator(std::unique_ptr<IOperationFactory>&& factory)
: factory_(std::move(factory)) {};



Result<double> Calculator::calculateResult(std::vector<std::string> infixVector) const
{
    if (infixVector.empty())
    {
        return Result<double>(nan(""), false, "No valid equation");
    }

    Result<std::stack<std::string>> postfixResult = infixToPostfix(infixVector);
    if (!postfixResult.isValid())
    {
        return Result<double>(nan(""), false, postfixResult.getError());
    }

    std::stack<std::string> resultStack = postfixResult.getResult();
    Result<std::unique_ptr<IMathOperation>> operationResult = extractOperation(resultStack);
    if (!operationResult.isValid())
    {
        return Result<double>(nan(""), false, operationResult.getError());
    }
    
    double result = operationResult.getResult()->calculate();
    return Result<double>(std::move(result));
};



Result<std::unique_ptr<IMathOperation>> Calculator::extractOperation(std::stack<std::string> &postfixStack) const
{
    if (postfixStack.empty())
    {
        return Result<std::unique_ptr<IMathOperation>>(std::move(std::make_unique<NotANumber>()), false, "Empty equation");
    }
    
    Result<std::unique_ptr<IMathOperation>> lhs;
    Result<std::unique_ptr<IMathOperation>> rhs;
    std::unique_ptr<IMathOperation> operationUPtr;
    double value;
    std::string operatorName;

    switch(postfixStack.top()[0])
    {
        case '-' :
            if (postfixStack.top().length() > 0 && (isdigit(postfixStack.top()[1]) || postfixStack.top()[1] == '.'))
            {
                value = stod(postfixStack.top());
                postfixStack.pop();
                operationUPtr = factory_->getConstantFor(value);
                return Result<std::unique_ptr<IMathOperation>>(std::move(operationUPtr));
                break;
            }
            //Fallthrough
        case '+' :
            //Fallthrough
        case '*' :
            //Fallthrough
        case '/' :
            operatorName = postfixStack.top();
            postfixStack.pop();
            if (postfixStack.empty())
            {
                return Result<std::unique_ptr<IMathOperation>>(std::make_unique<NotANumber>(), false, "Missing operands");
            }
            rhs = extractOperation(postfixStack);
            if (!rhs.isValid())
            {
                return Result<std::unique_ptr<IMathOperation>>(std::make_unique<NotANumber>(), false, rhs.getError());
            }
            
            if (postfixStack.empty())
            {
                return Result<std::unique_ptr<IMathOperation>>(std::make_unique<NotANumber>(), false, "Missing operands");
            }
            lhs = extractOperation(postfixStack);
            if (!lhs.isValid())
            {
                return Result<std::unique_ptr<IMathOperation>>(std::make_unique<NotANumber>(), false, lhs.getError());
            }

            operationUPtr = factory_->getOperationFor(
                                operatorName, 
                                std::move(lhs.getResult()),
                                std::move(rhs.getResult())
                            );
            return Result<std::unique_ptr<IMathOperation>>(std::move(operationUPtr));
        
        case '0' :
            //Fallthrough
        case '1' :
            //Fallthrough
        case '2' :
            //Fallthrough
        case '3' :
            //Fallthrough
        case '4' :
            //Fallthrough
        case '5' :
            //Fallthrough
        case '6' :
            //Fallthrough
        case '7' :
            //Fallthrough
        case '8' :
            //Fallthrough
        case '9' :
            //Fallthrough
        case '.' :
            value = stod(postfixStack.top());
            postfixStack.pop();
            operationUPtr = factory_->getConstantFor(value);
            return Result<std::unique_ptr<IMathOperation>>(std::move(operationUPtr));
        
        default :
            return Result<std::unique_ptr<IMathOperation>>(std::make_unique<NotANumber>(), false, "Invalid character in equation");
    }
};



Result<std::stack<std::string>> Calculator::infixToPostfix(std::vector<std::string> infixVector)
{
    std::stack<std::string> outputStack;
    std::stack<char> operatorStack;    

    for (auto it = infixVector.cbegin(); it != infixVector.cend(); it++)
    {
        std::string readNumber = "";
        bool previousValueIsAParenthesis = it > infixVector.cbegin() && (*(it - 1))[0] == ')';
        bool previousValueIsANumber      = it > infixVector.cbegin() && (isdigit((*(it - 1))[(*(it - 1)).length() - 1]) || (*(it - 1))[(*(it - 1)).length() - 1] == '.');
        Result<bool> plusMinusResult;

        switch ((*it)[0])
        {
            case '0' :
                //Fallthrough
            case '1' :
                //Fallthrough
            case '2' :
                //Fallthrough
            case '3' :
                //Fallthrough
            case '4' :
                //Fallthrough
            case '5' :
                //Fallthrough
            case '6' :
                //Fallthrough
            case '7' :
                //Fallthrough
            case '8' :
                //Fallthrough
            case '9' :
                //Fallthrough
            case '.' :
                if (previousValueIsAParenthesis)
                {
                    return Result<std::stack<std::string>>(
                               std::move(outputStack),
                               false,
                               "Missing operator after parenthesis");
                }
                outputStack.push(*it);
                break;

            case '+' :
                //Fallthrough
            case '-' :
                plusMinusResult = plusMinusInfixCase(it, outputStack, operatorStack, previousValueIsAParenthesis);
                if(!plusMinusResult.isValid())
                {
                    return Result<std::stack<std::string>>(std::move(outputStack), false, plusMinusResult.getError());
                }
                break;

            case '*' :
                //Fallthrough
            case '/' :
                while (!operatorStack.empty() && (operatorStack.top() == '*' || operatorStack.top() == '/'))
                {
                    outputStack.push(std::string(1, operatorStack.top()));
                    operatorStack.pop();
                }
                operatorStack.push((*it)[0]);
                break;

            case '(' :
                if (previousValueIsANumber)
                {

                    return Result<std::stack<std::string>>(
                               std::move(outputStack),
                               false,
                               "Missing operator before parenthesis");
                }
                operatorStack.push('(');
                break;
            
            case ')' :
                if (!operatorStack.empty())
                {
                    while (operatorStack.top() != '(')
                    {
                        outputStack.push(std::string(1, operatorStack.top()));
                        operatorStack.pop();
                        if (operatorStack.empty())
                        {
                            return Result<std::stack<std::string>>(
                               std::move(outputStack),
                               false,
                               "Too many closing parenthesis");
                        }
                    }
                }
                if (operatorStack.empty())
                {
                    return Result<std::stack<std::string>>(
                               std::move(outputStack),
                               false,
                               "Too many closing parenthesis");
                }
                operatorStack.pop();
                break;
            
            default:
                return Result<std::stack<std::string>>(std::move(outputStack), false, "Invalid character in equation");
        }
    }

    while (!operatorStack.empty())
    {
        if (operatorStack.top() == '(')
        {
            return Result<std::stack<std::string>>(
                               std::move(outputStack),
                               false,
                               "Missing closing parenthesis");
        }
        outputStack.push(std::string(1, operatorStack.top()));
        operatorStack.pop();
    }
    return Result<std::stack<std::string>>(std::move(outputStack));
};


Result<bool> Calculator::plusMinusInfixCase(
    std::vector<std::string>::const_iterator &it,
    std::stack<std::string>                  &outputStack,
    std::stack<char>                         &operatorStack,
    bool                                     previousValueIsAParenthesis)
{
    // If symbol contains more than just '-'
    if (it->length() > 1)
    {
        // Then treat the '-' as a negative rather than subtraction
        if (previousValueIsAParenthesis)
        {
            return Result<bool>(
                    false,
                    false,
                    "Missing operator after parenthesis");
        }
        outputStack.push(*it);
    }
    else
    {
        while (!operatorStack.empty() && operatorStack.top() != '(')
        {
            outputStack.push(std::string(1, operatorStack.top()));
            operatorStack.pop();
        }
        operatorStack.push((*it)[0]);
    }
    return Result<bool>(true);
}