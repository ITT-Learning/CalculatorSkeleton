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
#include <memory>

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



Result<double> Calculator::calculateResult(std::string equationString) const
{
    if (equationString.empty())
    {
        return Result<double>(std::make_unique<double>(nan("")), false, "No valid equation");
    }

    Result<std::stack<std::string>> postfixResult = infixToPostfix(equationString);
    if (!postfixResult.isValid())
    {
        return Result<double>(std::make_unique<double>(nan("")), false, postfixResult.getError());
    }

    std::stack<std::string> resultStack = *(postfixResult.consumeResult());
    Result<IMathOperation> operationResult = extractOperation(resultStack);
    if(!operationResult.isValid())
    {
        return Result<double>(std::make_unique<double>(nan("")), false, operationResult.getError());
    }
    
    double result = operationResult.consumeResult()->calculate();
    return Result<double>(std::make_unique<double>(result));
};



Result<IMathOperation> Calculator::extractOperation(std::stack<std::string> &postfixStack) const
{
    if (postfixStack.empty())
    {
        throw "Empty equation";
    }
    Result<IMathOperation> lhs;
    Result<IMathOperation> rhs;
    std::unique_ptr<IMathOperation> operationUPtr;
    double value;

    std::string topValue;
    switch(postfixStack.top()[0])
    {
        case '+' :
            //Fallthrough
        // FIXME make '-' also apply to negative numbers
        case '-' :
            //Fallthrough
        case '*' :
            //Fallthrough
        case '/' :
            topValue = postfixStack.top();
            postfixStack.pop();
            if(postfixStack.empty())
            {
                return Result<IMathOperation>(std::make_unique<NotANumber>(), false, "Missing operands");
            }
            rhs = extractOperation(postfixStack);
            if(!rhs.isValid())
            {
                return Result<IMathOperation>(std::make_unique<NotANumber>(), false, rhs.getError());
            }
            
            if(postfixStack.empty())
            {
                return Result<IMathOperation>(std::make_unique<NotANumber>(), false, "Missing operands");
            }
            lhs = extractOperation(postfixStack);
            if(!lhs.isValid())
            {
                return Result<IMathOperation>(std::make_unique<NotANumber>(), false, lhs.getError());
            }

            operationUPtr = factory_->getOperationFor(
                             topValue, 
                             lhs.consumeResult(),
                             rhs.consumeResult()
                         );
            return Result<IMathOperation>(std::move(operationUPtr));
        
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
            operationUPtr = factory_->getOperationFor(value);
            return Result<IMathOperation>(std::move(operationUPtr));
        
        default :
            return Result<IMathOperation>(std::make_unique<NotANumber>(), false, "Invalid equation format");
    }
};



Result<std::stack<std::string>> Calculator::infixToPostfix(std::string infixString)
{
    std::stack<std::string> outputStack;
    std::stack<char> operatorStack;    

    for(int i = 0; i < infixString.length(); i++)
    {
        std::string readNumber = "";
        switch(infixString[i])
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
                if (i > 0 && infixString[i - 1] == ')')
                {
                    return Result<std::stack<std::string>>(
                               std::make_unique<std::stack<std::string>>(outputStack),
                               false,
                               "Missing operator after parenthesis");
                }
                readNumber = "";
                while (i < infixString.length() && (isdigit(infixString[i]) || infixString[i] == '.'))
                {
                    readNumber += infixString[i++];
                }
                i--;
                outputStack.push(readNumber);
                break;

            case '+' :
                //Fallthrough
            // FIXME allow '-' to be used to denote negative numbers
            case '-' :
                while (!operatorStack.empty() && operatorStack.top() != '(')
                {
                    outputStack.push(std::string(1, operatorStack.top()));
                    operatorStack.pop();
                }
                operatorStack.push(infixString[i]);
                break;

            case '*' :
                //Fallthrough
            case '/' :
                while (!operatorStack.empty() && (operatorStack.top() == '*' || operatorStack.top() == '/'))
                {
                    outputStack.push(std::string(1, operatorStack.top()));
                    operatorStack.pop();
                }
                operatorStack.push(infixString[i]);
                break;

            case '(' :
                if (i > 0 && (isdigit(infixString[i - 1]) || infixString[i - 1] == '.'))
                {

                    return Result<std::stack<std::string>>(
                               std::make_unique<std::stack<std::string>>(outputStack),
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
                               std::make_unique<std::stack<std::string>>(outputStack),
                               false,
                               "Too many closing parentheses");
                        }
                    }
                }
                if (operatorStack.empty())
                {
                    return Result<std::stack<std::string>>(
                               std::make_unique<std::stack<std::string>>(outputStack),
                               false,
                               "Too many closing parentheses");
                }
                operatorStack.pop();
                break;
        }
    }

    while (!operatorStack.empty())
    {
        if (operatorStack.top() == '(')
        {
            return Result<std::stack<std::string>>(
                               std::make_unique<std::stack<std::string>>(outputStack),
                               false,
                               "Missing closing paretheses");
        }
        outputStack.push(std::string(1, operatorStack.top()));
        operatorStack.pop();
    }
    return Result<std::stack<std::string>>(std::make_unique<std::stack<std::string>>(outputStack));
};



std::string Calculator::sanitizeString(std::string unsanitizedString)
{
    std::string compactString = "";
    for(int i = 0; i < unsanitizedString.length(); i++)
    {
        if (isdigit(unsanitizedString[i]) || unsanitizedString[i] == '(' || unsanitizedString[i] == ')' || unsanitizedString[i] == '.' || unsanitizedString[i] == '+' || unsanitizedString[i] == '-' || unsanitizedString[i] == '*' || unsanitizedString[i] == '/')
        {
            compactString += unsanitizedString[i];
        }
    }

    return compactString;
};