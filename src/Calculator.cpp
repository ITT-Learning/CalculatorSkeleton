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

double Calculator::calculate(std::string operationString)
{
    operationString = compactString(operationString);
    std::stack<std::string> postfixStack = infixToPostfix(operationString);
    IMathOperation* topLevelOperation = extractOperation(postfixStack);
    double result = topLevelOperation->calculate();
    delete topLevelOperation;
    return result;
};

IMathOperation* extractOperation(std::stack<std::string> postfixStack)
{
    switch(postfixStack.top()[0])
    {
        case '+':
            postfixStack.pop();
            IMathOperation* rhs = extractOperation(postfixStack);
            IMathOperation* lhs = extractOperation(postfixStack);
            return new Addition(lhs, rhs);

        case '-':
            postfixStack.pop();
            IMathOperation* rhs = extractOperation(postfixStack);
            IMathOperation* lhs = extractOperation(postfixStack);
            return new Subtraction(lhs, rhs);

        case '*':
            postfixStack.pop();
            IMathOperation* rhs = extractOperation(postfixStack);
            IMathOperation* lhs = extractOperation(postfixStack);
            return new Multiplication(lhs, rhs);

        case '/':
            postfixStack.pop();
            IMathOperation* rhs = extractOperation(postfixStack);
            IMathOperation* lhs = extractOperation(postfixStack);
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
            double constValue = stod(postfixStack.top());
            return new Constant(constValue);
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
                while(isdigit(infixString[i]) || infixString[i] == '.')
                    readNumber += infixString[i++];
                outputStack.push(readNumber);
                break;

            case '+':
            case '-':
                while(operatorStack.top() != '(')
                {
                    outputStack.push(std::string(1, operatorStack.top()));
                    operatorStack.pop();
                }
                operatorStack.push(infixString[i]);
                break;

            case '*':
            case '/':
                while(operatorStack.top() == '*' || operatorStack.top() == '/')
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
                while(operatorStack.top() != '(')
                {
                    outputStack.push(std::string(1, operatorStack.top()));
                    operatorStack.pop();
                }
                operatorStack.pop();
                break;
        }
    }

    while(!operatorStack.empty())
    {
        outputStack.push(std::string(1, operatorStack.top()));
        operatorStack.pop();
    }
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

std::string stringStart(std::string str, int bound)
{
    return str.substr(0, bound);
};

std::string stringEnd(std::string str, int bound)
{
    return str.substr(bound, str.length() - bound);
};

double Calculator::extractLhs(std::string lhsString)
{
    int lhsStart;
    for(lhsStart = lhsString.length();
        lhsStart > 0 && (std::isdigit(lhsString[lhsStart]) || lhsString[lhsStart] == '.');
        --lhsStart);
    
    std::string lhsString = stringEnd(lhsString, lhsStart);
    return parseNumber(lhsString);
};

double Calculator::extractRhs(std::string rhsString)
{
    int rhsEnd;
    for(rhsEnd = 0;
        rhsEnd < rhsString.length() && (std::isdigit(rhsString[rhsEnd]) || rhsString[rhsEnd] == '.');
        ++rhsEnd);
    
    std::string lhsString = stringStart(rhsString, rhsEnd);
    return parseNumber(lhsString);
};

std::string Calculator::compactString(std::string str)
{
    std::string compactString = "";
    for(int i = 0; i < str.length(); i++)
        if(isgraph(str[i]))
            compactString += str[i];

    return compactString;
};

// Add Function definitions here.