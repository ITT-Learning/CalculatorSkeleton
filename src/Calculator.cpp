////////////////////////////////////////////////////////////////////////////
/**
 *  @file   Calculator.cpp
 *  @date   Fri April 16 2021
 *  @brief  Funtions that support main.cpp
 */
////////////////////////////////////////////////////////////////////////////

#include "Calculator.h"
#include <sstream>

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

    while (operation != quit)
    {
        try
        {
            GetInput(operation, a, b);
            result = Calculate(operation, a, b);
            OutputResult(result);
        }
        catch(const std::exception& e)
        {
            OutputError(e);
        }
    }
};

void OutputResult(double& result, std::ostream& out)
{
    out << " = " << result << std::endl;
}

void OutputError(const std::exception& e, std::ostream& out)
{
    out << e.what() << std::endl;
}

void GetInput(char& operation, double& a, double& b) 
{
    std::string inputString;
    std::getline(std::cin, inputString);
    std::istringstream inputStream(inputString);

    //if contains q quit
    if (inputString.find(quit) != std::string::npos)
    {
        operation = quit;
        throw std::invalid_argument( quitMessage );
    }
    else
    {
        inputStream >> a >> operation >> b;
    };
};

double Calculate(char& operation, double a, double b)
{
    double result;

    if (operation == '+') 
    {
        result = Addition(a, b);
    }
    else if (operation == '-')
    {
        result = Subtraction(a, b);
    }
    else if (operation == '*')
    {
        result = Multiplication(a, b);
    }
    else if (operation == '/')
    {
        result = Division(a, b);
    }
    else
    {
        throw std::invalid_argument( unknownOperationError );
    };

    return result;
};

double Addition(double a, double b)
{
    return a + b;
};

double Subtraction(double a, double b)
{
    return a - b;
};

double Multiplication(double a, double b)
{
    return a * b;
};

double Division(double a, double b)
{
    if (b == 0)
    {
        throw std::invalid_argument( divideByZeroError );
    }

    return a / b;
};