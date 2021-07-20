////////////////////////////////////////////////////////////////////////////
/**
 *  @file   Calculator.cpp
 *  @date   Fri April 16 2021
 *  @brief  Funtions that support main.cpp
 */
////////////////////////////////////////////////////////////////////////////

#include "Calculator.h"
#include <sstream>

namespace calculator 
{
    const char quit = 'q';
    const char quitMessage[] = "Quitting!";
    const char unknownOperationError[] = "Error: Unknown operation";
    const char divideByZeroError[] = "Error: Division by zero";

    void RunCalculator()
    {
        std::cout << "Gary's Calculator C++ learning project." << std::endl;
        std::cout << "Enter an expression, like 1 + 2 and ENTER. Valid operations are +-*/" << std::endl;

        double a, b, result;
        char operation;
        const char* errorResult;

        while (operation != quit)
        {
            errorResult = GetInput(operation, a, b);
            if (errorResult == nullptr)
            {
                errorResult = Calculate(operation, a, b, result);
            }

            if (errorResult == nullptr)
            {
                OutputResult(result);
            }
            else
            {
                OutputError(errorResult);
            }
        }
    };

    void OutputResult(const double& result, std::ostream& out)
    {
        out << " = " << result << std::endl;
    }

    void OutputError(const char* errorString, std::ostream& out)
    {
        out << errorString << std::endl;
    }

    const char* GetInput(char& operation, double& a, double& b, std::istream& input) 
    {
        const char* errorString = nullptr;
        std::string inputString;
        std::getline(input, inputString);
        std::istringstream inputStream(inputString);

        //if contains q quit
        if (inputString.find(quit) != std::string::npos)
        {
            operation = quit;
            errorString = quitMessage;
        }
        else
        {
            inputStream >> a >> operation >> b;
        };

        return errorString;
    };

    const char* Calculate(const char& operation, const double a, const double b, double& result)
    {
        const char* errorString = nullptr; 
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
                if (b == 0)
                {
                    errorString = divideByZeroError;
                }
                else
                {
                    result = a / b;
                }
     
                break;
            }
            default:
            {
                errorString = unknownOperationError;
                break;
            }
        }
        
        return errorString;
    };
}