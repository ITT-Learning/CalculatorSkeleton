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

#include "IOperationFactory.h"
#include "Constant.h"
#include "Addition.h"
#include "Subtraction.h"
#include "Multiplication.h"
#include "Division.h"
#include "NotANumber.h"



Calculator::Calculator(std::unique_ptr<IOperationFactory>&& factory)
: factory_(std::move(factory)) {};



double Calculator::calculate(std::string equationString)
{
    if (equationString.empty())
    {
        return nan("");
    }
    std::stack<std::string> postfixStack = infixToPostfix(equationString);
    std::unique_ptr<IMathOperation> topLevelOperation = extractOperation(postfixStack);
    double result = topLevelOperation->calculate();
    return result;
};



std::unique_ptr<IMathOperation> Calculator::extractOperation(std::stack<std::string> &postfixStack)
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



std::stack<std::string> Calculator::infixToPostfix(std::string infixString)
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
                    throw "Missing operator after parenthesis";
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

                    throw "Missing operator before parenthesis";
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
                            throw "Too many closing parentheses";
                        }
                    }
                }
                if (operatorStack.empty())
                {
                    throw "Too many closing parentheses";
                }
                operatorStack.pop();
                break;
        }
    }

    while (!operatorStack.empty())
    {
        if (operatorStack.top() == '(')
        {
            throw "Missing closing paretheses";
        }
        outputStack.push(std::string(1, operatorStack.top()));
        operatorStack.pop();
    }
    return outputStack;
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