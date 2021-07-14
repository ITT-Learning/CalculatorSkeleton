////////////////////////////////////////////////////////////////////////////
/**
 *  @file   Calculator.cpp
 *  @date   Fri April 16 2021
 *  @brief  Funtions that support main.cpp
 */
////////////////////////////////////////////////////////////////////////////

#include "Calculator.h"

const char quitMessage[] = "Quitting!";
const char unknownOperationError[] = "Unknwon operation!";

void RunCalculator()
{
    std::cout << "Gary's Calculator C++ learning project." << std::endl;
    std::cout << "Enter an expression, like 1 + 2 and ENTER. Valid operations are +-*/" << std::endl;

    double a, b, result;
    char operation;

    const char* errorMessage = GetInput(operation, a, b);

    while (errorMessage == nullptr)
    {
        errorMessage = Calculate(operation, a, b, result);
        if (errorMessage == nullptr)
        {
            std::cout << " = " << result << std::endl;
            errorMessage = GetInput(operation, a, b);
        }     
    }

    std::cout << errorMessage << std::endl;
}

const char* GetInput(char& operation, double& a, double& b) 
{
    const char* errorMessage = nullptr;
    double result;

    std::cin >> a >> operation >> b;

    if (operation == 'q')
    {
        errorMessage = quitMessage;
    }

    return errorMessage;
}

const char* Calculate(char operation, double a, double b, double& result)
{
    const char* errorMessage = nullptr;

    switch (operation)
    {
        case '+':
        {
            result = a + b;
            break;
        }
        case '-':
        {
           result = a - b;
            break;
        }
        case '*':
        {
            result = a * b;
            break;
        }
        case '/':
        {
            result = a / b;
            break;
        }
        default:
            errorMessage = unknownOperationError;
    };

    return errorMessage;
};
