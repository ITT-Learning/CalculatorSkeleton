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
#include "PostfixResult.h"
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
        return Result<double>(nan(""), false, "No valid equation");
    }
    Result<std::stack<std::string>> postfixResult = infixToPostfix(equationString);
    if (!postfixResult.isValid())
    {
        return Result<double>(nan(""), false, postfixResult.getErrorMessage());
    }
    // std::stack<std::string> postfixStack = postfixResult.resultStack_;
    // TODO return a MathResult object continaing a double of the result, error/nan flags
    std::unique_ptr<IMathOperation> topLevelOperation = extractOperation(postfixResult.getResult());
    double result = topLevelOperation->calculate();
    return Result<double>(result);
};



Result<std::unique_ptr<IMathOperation>> Calculator::extractOperation(std::stack<std::string> &postfixStack) const
{
    if (postfixStack.empty())
    {
        throw "Empty equation";
    }
    std::unique_ptr<IMathOperation> lhs;
    std::unique_ptr<IMathOperation> rhs;
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
            rhs = extractOperation(postfixStack);
            lhs = extractOperation(postfixStack);
            return factory_->getOperationFor(topValue, std::move(lhs), std::move(rhs));
        
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
            return factory_->getOperationFor(value);
        
        default :
            return std::make_unique<NotANumber>();
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
                    return Result<std::stack<std::string>>(outputStack, false, "Missing operator after parenthesis");
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

                    return Result<std::stack<std::string>>(outputStack, false, "Missing operator before parenthesis");
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
                            return Result<std::stack<std::string>>(outputStack, false, "Too many closing parentheses");
                        }
                    }
                }
                if (operatorStack.empty())
                {
                    return Result<std::stack<std::string>>(outputStack, false, "Too many closing parentheses");
                }
                operatorStack.pop();
                break;
        }
    }

    while (!operatorStack.empty())
    {
        if (operatorStack.top() == '(')
        {
            return Result<std::stack<std::string>>(outputStack, false, "Missing closing paretheses");
        }
        outputStack.push(std::string(1, operatorStack.top()));
        operatorStack.pop();
    }
    return Result<std::stack<std::string>>(outputStack);
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