////////////////////////////////////////////////////////////////////////////
/**
 *  @file   Calculator.cpp
 *  @date   Fri April 16 2021
 *  @brief  Funtions that support main.cpp
 */
////////////////////////////////////////////////////////////////////////////

#include "Calculator.h"

#include <cctype>
#include <stack>

#include "Constant.h"
#include "Addition.h"
#include "Subtraction.h"
#include "Multiplication.h"
#include "Division.h"

double Calculator::calculate(std::string equationString)
{
    if (equationString.empty())
        return 0;
    std::stack<std::string> postfixStack = infixToPostfix(equationString);
    IMathOperation* topLevelOperation = extractOperation(postfixStack);
    double result = topLevelOperation->calculate();
    delete topLevelOperation;
    return result;
};



IMathOperation* Calculator::extractOperation(std::stack<std::string> &postfixStack)
{
    if (postfixStack.empty())
        throw "Empty equation";
    IMathOperation* lhs;
    IMathOperation* rhs;
    double value;
    switch(postfixStack.top()[0])
    {
        case '+' :
            postfixStack.pop();
            if (postfixStack.empty()) throw "Missing operands";
            rhs = extractOperation(postfixStack);
            if (postfixStack.empty()) throw "Missing operands";
            lhs = extractOperation(postfixStack);
            return new Addition(lhs, rhs);

        case '-' :
            postfixStack.pop();
            if (postfixStack.empty()) throw "Missing operands";
            rhs = extractOperation(postfixStack);
            if (postfixStack.empty()) throw "Missing operands";
            lhs = extractOperation(postfixStack);
            return new Subtraction(lhs, rhs);

        case '*' :
            postfixStack.pop();
            if (postfixStack.empty()) throw "Missing operands";
            rhs = extractOperation(postfixStack);
            if (postfixStack.empty()) throw "Missing operands";
            lhs = extractOperation(postfixStack);
            return new Multiplication(lhs, rhs);

        case '/' :
            postfixStack.pop();
            if (postfixStack.empty()) throw "Missing operands";
            rhs = extractOperation(postfixStack);
            if (postfixStack.empty()) throw "Missing operands";
            lhs = extractOperation(postfixStack);
            return new Division(lhs, rhs);
        
        case '0' :
        case '1' :
        case '2' :
        case '3' :
        case '4' :
        case '5' :
        case '6' :
        case '7' :
        case '8' :
        case '9' :
        case '.' :
            value = stod(postfixStack.top());
            postfixStack.pop();
            return new Constant(value);
        
        default :
            throw "Invalid equation format";
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
            case '1' :
            case '2' :
            case '3' :
            case '4' :
            case '5' :
            case '6' :
            case '7' :
            case '8' :
            case '9' :
            case '.' :
                if (i > 0 && infixString[i - 1] == ')')
                    throw "Missing operator after parenthesis";
                readNumber = "";
                while (i < infixString.length() && (isdigit(infixString[i]) || infixString[i] == '.'))
                    readNumber += infixString[i++];
                i--;
                outputStack.push(readNumber);
                break;

            case '+' :
            case '-' :
                while (!operatorStack.empty() && operatorStack.top() != '(')
                {
                    outputStack.push(std::string(1, operatorStack.top()));
                    operatorStack.pop();
                }
                operatorStack.push(infixString[i]);
                break;

            case '*' :
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
                    throw "Missing operator before parenthesis";
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
                            throw "Too many closing parentheses";
                    }
                }
                if (operatorStack.empty())
                    throw "Too many closing parentheses";
                operatorStack.pop();
                break;
        }
    }

    while (!operatorStack.empty())
    {
        if (operatorStack.top() == '(')
            throw "Missing closing paretheses";
        outputStack.push(std::string(1, operatorStack.top()));
        operatorStack.pop();
    }
    return outputStack;
};



std::string Calculator::sanitizeString(std::string unsanitizedString)
{
    std::string compactString = "";
    for(int i = 0; i < unsanitizedString.length(); i++)
        if (isdigit(unsanitizedString[i]) || unsanitizedString[i] == '(' || unsanitizedString[i] == ')' || unsanitizedString[i] == '.' || unsanitizedString[i] == '+' || unsanitizedString[i] == '-' || unsanitizedString[i] == '*' || unsanitizedString[i] == '/')
            compactString += unsanitizedString[i];

    return compactString;
};