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
    if (!operationResult.isValid())
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
        return Result<IMathOperation>(std::make_unique<NotANumber>(), false, "Empty equation");
    }
    
    Result<IMathOperation> lhs;
    Result<IMathOperation> rhs;
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
                return Result<IMathOperation>(std::move(operationUPtr));
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
                return Result<IMathOperation>(std::make_unique<NotANumber>(), false, "Missing operands");
            }
            rhs = extractOperation(postfixStack);
            if (!rhs.isValid())
            {
                return Result<IMathOperation>(std::make_unique<NotANumber>(), false, rhs.getError());
            }
            
            if (postfixStack.empty())
            {
                return Result<IMathOperation>(std::make_unique<NotANumber>(), false, "Missing operands");
            }
            lhs = extractOperation(postfixStack);
            if (!lhs.isValid())
            {
                return Result<IMathOperation>(std::make_unique<NotANumber>(), false, lhs.getError());
            }

            operationUPtr = factory_->getOperationFor(
                                operatorName, 
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
            operationUPtr = factory_->getConstantFor(value);
            return Result<IMathOperation>(std::move(operationUPtr));
        
        default :
            return Result<IMathOperation>(std::make_unique<NotANumber>(), false, "Invalid character in equation");
    }
};



Result<std::stack<std::string>> Calculator::infixToPostfix(std::string infixString)
{
    std::stack<std::string> outputStack;
    std::stack<char> operatorStack;    

    for (int i = 0; i < infixString.length(); i++)
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
                readNumber = extractNextNumberFromString(infixString.substr(i));
                i += readNumber.length() - 1;
                outputStack.push(readNumber);
                break;

            case '-' :
                // If the previous symbol isn't part of a number or a right parenthesis
                if (i == 0 || !(isdigit(infixString[i - 1]) || infixString[i - 1] == '.' || infixString[i - 1] == ')'))
                {
                    // Then treat the '-' as a negative rather than subtraction
                    if (i > 0 && infixString[i - 1] == ')')
                    {
                        return Result<std::stack<std::string>>(
                                std::make_unique<std::stack<std::string>>(outputStack),
                                false,
                                "Missing operator after parenthesis");
                    }
                    readNumber = extractNextNumberFromString(infixString.substr(i));
                    i += readNumber.length() - 1;
                    outputStack.push(readNumber);
                    break;
                }
                //Fallthrough
            case '+' :
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
                               "Too many closing parenthesis");
                        }
                    }
                }
                if (operatorStack.empty())
                {
                    return Result<std::stack<std::string>>(
                               std::make_unique<std::stack<std::string>>(outputStack),
                               false,
                               "Too many closing parenthesis");
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
                               "Missing closing parenthesis");
        }
        outputStack.push(std::string(1, operatorStack.top()));
        operatorStack.pop();
    }
    return Result<std::stack<std::string>>(std::make_unique<std::stack<std::string>>(outputStack));
};



std::string Calculator::sanitizeString(std::string unsanitizedString)
{
    std::string compactString = "";
    for (int i = 0; i < unsanitizedString.length(); i++)
    {
        bool isAlphaNumeric = isalnum(unsanitizedString[i]);
        bool isMathOperator = unsanitizedString[i] == '(' || 
                              unsanitizedString[i] == ')' ||
                              unsanitizedString[i] == '+' ||
                              unsanitizedString[i] == '-' ||
                              unsanitizedString[i] == '*' ||
                              unsanitizedString[i] == '/';
        bool isDecimalPoint = unsanitizedString[i] == '.';
        if (isAlphaNumeric || isMathOperator || isDecimalPoint)
        {
            compactString += tolower(unsanitizedString[i]);
        }
    }

    return compactString;
};



std::string Calculator::extractNextNumberFromString(std::string str)
{
    std::string readNumber = "";
    for (int i = 0; i < str.length() && (isdigit(str[i]) || str[i] == '.' || str[i] == '-'); i++)
    {
        readNumber += str[i];
    }
    return readNumber;
};