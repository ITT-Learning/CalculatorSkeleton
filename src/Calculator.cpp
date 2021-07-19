////////////////////////////////////////////////////////////////////////////
/**
 *  @file   Calculator.cpp
 *  @date   Fri April 16 2021
 *  @brief  Funtions that support main.cpp
 */
////////////////////////////////////////////////////////////////////////////

#include "Calculator.h"

const char quitMessage[] = "Quitting!";
const char unknownOperationError[] = "Error: Unknown operation";
const char divideByZeroError[] = "Error: Division by zero";

void RunCalculator()
{
    std::cout << "Gary's Calculator C++ learning project." << std::endl;
    std::cout << "Enter an expression, like 1 + 2 and ENTER. Valid operations are +-*/" << std::endl;

    double a, b, result;
    char operation = ' ';

    while (operation != 'q')
    {
        try
        {
            GetInput(operation, a, b);
            result = Calculate(operation, a, b);
            std::cout << "= " << result << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }
    }
}

void GetInput(char& operation, double& a, double& b) 
{
    std::cin >> a >> operation >> b;

    if (operation == 'q')
    {
        throw std::invalid_argument( quitMessage ); //std::exception(quitMessage);
    }
};

double Calculate(char operation, double a, double b)
{
    double result;

    switch (operation)
    {
        case '+':
        {
            result = Addition(a, b);
            break;
        }
        case '-':
        {
            result = Subtraction(a, b);
            break;
        }
        case '*':
        {
            result = Multiplication(a, b);
            break;
        }
        case '/':
        {
            result = Division(a, b);
            break;
        }
        default:
            throw std::invalid_argument( unknownOperationError ); //std::exception(unknownOperationError);;
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

double Division(double a, double b)
{
    if (b == 0)
    {
        throw std::invalid_argument( divideByZeroError ); //std::exception(quitMessage);
    }

    return a / b;
};

double Multiplication(double a, double b)
{
    return a * b;
};