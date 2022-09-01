////////////////////////////////////////////////////////////////////////////
/**
 *  @file   Calculator.cpp
 *  @date   Fri April 16 2021
 *  @brief  Funtions that support main.cpp
 */
////////////////////////////////////////////////////////////////////////////

#include "Calculator.h"
#include "Constant.h"
#include "Addition.h"
#include "Subtraction.h"
#include "Multiplication.h"
#include "Division.h"
#include <cctype>
#include <stack>

IMathOperation* extractOperation(std::stack<std::string>);

double Calculator::calculate(std::string operationString)
{
    if(operationString.empty())
        return 0;
    std::stack<std::string> postfixStack = infixToPostfix(operationString);
    IMathOperation* topLevelOperation = extractOperation(postfixStack);
    double result = topLevelOperation->calculate();
    delete topLevelOperation;
    return result;
};

IMathOperation* Calculator::extractOperation(std::stack<std::string> &postfixStack)
{
    IMathOperation* lhs;
    IMathOperation* rhs;
    double value;
    switch(postfixStack.top()[0])
    {
        case '+':
            postfixStack.pop();
            if(postfixStack.empty()) throw "Missing operands";
            rhs = extractOperation(postfixStack);
            if(postfixStack.empty()) throw "Missing operands";
            lhs = extractOperation(postfixStack);
            return new Addition(lhs, rhs);

        case '-':
            postfixStack.pop();
            if(postfixStack.empty()) throw "Missing operands";
            rhs = extractOperation(postfixStack);
            if(postfixStack.empty()) throw "Missing operands";
            lhs = extractOperation(postfixStack);
            return new Subtraction(lhs, rhs);

        case '*':
            postfixStack.pop();
            if(postfixStack.empty()) throw "Missing operands";
            rhs = extractOperation(postfixStack);
            if(postfixStack.empty()) throw "Missing operands";
            lhs = extractOperation(postfixStack);
            return new Multiplication(lhs, rhs);

        case '/':
            postfixStack.pop();
            if(postfixStack.empty()) throw "Missing operands";
            rhs = extractOperation(postfixStack);
            if(postfixStack.empty()) throw "Missing operands";
            lhs = extractOperation(postfixStack);
            return new Division(lhs, rhs);
        
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case '.':
            value = stod(postfixStack.top());
            postfixStack.pop();
            return new Constant(value);
        
        default:
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
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case '.':
                readNumber = "";
                while(i < infixString.length() && (isdigit(infixString[i]) || infixString[i] == '.'))
                    readNumber += infixString[i++];
                i--;
                outputStack.push(readNumber);
                break;

            case '+':
            case '-':
                while(!operatorStack.empty() && operatorStack.top() != '(')
                {
                    outputStack.push(std::string(1, operatorStack.top()));
                    operatorStack.pop();
                }
                operatorStack.push(infixString[i]);
                break;

            case '*':
            case '/':
                while(!operatorStack.empty() && (operatorStack.top() == '*' || operatorStack.top() == '/'))
                {
                    outputStack.push(std::string(1, operatorStack.top()));
                    operatorStack.pop();
                }
                operatorStack.push(infixString[i]);
                break;

            case '(':
                operatorStack.push('(');
                break;
            
            case ')':
                if(!operatorStack.empty())
                {
                    while(operatorStack.top() != '(')
                    {
                        outputStack.push(std::string(1, operatorStack.top()));
                        operatorStack.pop();
                        if(operatorStack.empty())
                            throw "Too many closing parentheses";
                    }
                }
                if(operatorStack.empty())
                    throw "Too many closing parentheses";
                operatorStack.pop();
                break;
        }
    }

    while(!operatorStack.empty())
    {
        if(operatorStack.top() == '(')
            throw "Missing closing paretheses";
        outputStack.push(std::string(1, operatorStack.top()));
        operatorStack.pop();
    }
    return outputStack;
};

double Calculator::parseNumber(std::string str)
{
    double result = 0;
    int decimalPlaces = -1;

    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == '.' || decimalPlaces > -1)
            decimalPlaces++;

        if(str[i] != '.')
        {
            result *= 10;
            switch(str[i])
            {
                case '0': result += 0; break;
                case '1': result += 1; break;
                case '2': result += 2; break;
                case '3': result += 3; break;
                case '4': result += 4; break;
                case '5': result += 5; break;
                case '6': result += 6; break;
                case '7': result += 7; break;
                case '8': result += 8; break;
                case '9': result += 9; break;
            }
        }
    }

    for(int i = 0; i < decimalPlaces; i++)
    {
        result /= 10;
    }

    return result;
};

std::string Calculator::sanitizeString(std::string str)
{
    std::string compactString = "";
    for(int i = 0; i < str.length(); i++)
        if(isdigit(str[i]) || str[i] == '(' || str[i] == ')' || str[i] == '.' || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
            compactString += str[i];

    return compactString;
};