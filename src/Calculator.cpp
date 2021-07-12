////////////////////////////////////////////////////////////////////////////
/**
 *  @file   Calculator.cpp
 *  @date   Fri April 16 2021
 *  @brief  Funtions that support main.cpp
 */
////////////////////////////////////////////////////////////////////////////

#include "Calculator.h"

void RunCalculator()
{
    std::cout << "Gary's Calculator C++ learning project." << std::endl;
    std::cout << "Enter an expression, like 1 + 2 and ENTER. Valid operations are +-*/" << std::endl;
    int state = 0;
    double a = 0.0, b = 0.0;

    while (state == 0)
    {
        state = RenderCalculator();
    }
}

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

    return state;
}
