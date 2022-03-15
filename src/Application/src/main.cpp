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
#include "ExpressionSerializer.h"

int main() 
{
    std::cout << "Welcome to the Calculator C++ learning project - week 6!" << std::endl;
    std::vector<typename calculator::expression::ExpressionSerializer<double>::ExpressionBuffer> savedExpressions;
    bool userQuit{false};
    while(!userQuit)
    {
        userQuit = calculator::ConsoleIo<double>::handleInput(savedExpressions);
    }

    return 0;
}
