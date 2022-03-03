////////////////////////////////////////////////////////////////////////////
/**
 *  @file   main.cpp
 *  @date   Fri April 16 2021
 *  @brief  Entry Point of Calculator
 */
////////////////////////////////////////////////////////////////////////////

#include <iostream>

#include "ConsoleIo.h"
#include "ExpressionFactory.h"
#include "IExpression.h"

int main() 
{
    std::cout << "Welcome to the Calculator C++ learning project - week 5!" <<
                std::endl;
    bool userQuit{false};
    while(!userQuit)
    {
        userQuit = calculator::ConsoleIo<double>::handleInput();
    }

    return 0;
}

