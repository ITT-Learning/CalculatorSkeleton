////////////////////////////////////////////////////////////////////////////
/**
 *  @file   Calculator.cpp
 *  @date   Fri April 16 2021
 *  @brief  Funtions that support main.cpp
 */
////////////////////////////////////////////////////////////////////////////

#include "Calculator.h"

// Add Function definitions here.

void RunCalculator()
{
    std::cout << "Gary's Calculator C++ learning project...." << std::endl;
    int state = 0;
    double a = 0.0, b = 0.0;

    while (state == 0)
    {
        state = RenderCalculator();
    }
}

//double Add();
//double Subtract();
//double Multiply();
//double Divide();

int RenderCalculator()
{
    int state = 0;
    double a, b, result;
    char operation;

    std::cin >> a >> operation >> b;

    switch (operation)
    {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            result = a / b;
            break;
        default:
            state = 1;
    }

    if (0 == state) 
    {
        std::cout << " = " << result << std::endl;
    }
    else
    {
        std::cout << "Unkown Operation (" << operation << ")!" << std::endl;
    }

    // if ('+' == operation) 
    // {
    //     std::cout << " = " << a + b << std::endl;
    // }
    // else if ('-' == operation)
    // {
    //     std::cout << " = " << a - b << std::endl;
    // }
    // else if ('*' == operation)
    // {
    //     std::cout << " = " << a * b << std::endl;
    // }
    // else if ('/' == operation)
    // {
    //     std::cout << " = " << a / b << std::endl;
    // }
    // else if ('q' == operation)
    // {
    //     std::cout << "Quitting Calculator..." << std::endl;
    //     state = 1;
    // }
    // else
    // {
    //     std::cout << "Unkown Operation (" << operation << ")!" << std::endl;
    // }

    return state;
}
