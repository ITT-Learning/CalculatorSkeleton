////////////////////////////////////////////////////////////////////////////
/**
 *  @file   main.cpp
 *  @date   Fri April 16 2021
 *  @brief  Entry Point of Calculator
 */
////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>

#include <boost/algorithm/string.hpp>

#include "ExpressionFactory.h"
#include "ExpressionInterface.h"

bool handleInput();
void handleNonQuittingInput(const std::string &input);

int main() 
{
    std::cout << "Welcome to the Calculator C++ learning project - week 2!" <<
                std::endl;
    bool userQuit{false};
    while(!userQuit)
    {
        std::cout << "Please enter a simple expression (like 4 - 3 or "
                "12 * 7), or enter [Q]uit to quit: " << std::endl;
        userQuit = handleInput();
    }
    return 0;
}

bool handleInput()
{
    bool result{false};
    std::string input;
    std::getline(std::cin, input);
    boost::algorithm::to_lower(input);
    if(input == "quit" || input == "q")
    {
        result = true;
    }
    else
    {
        handleNonQuittingInput(input);
    }
    return result;
}

void handleNonQuittingInput(const std::string &input)
{
    auto expression = calculator::expression::ExpressionFactory<int>::
            parseFromSingleOperationString(input);
    if(expression)
    {
        auto optionalValue = expression->calculateExpression();
        if(optionalValue)
        {
            std::cout << "= " << *optionalValue << std::endl;
        }
        else
        {
            std::cout << "A problem happened during calculation. Did you "
                    "divide by zero?" << std::endl;
        }
    }
    else
    {
        std::cout << "Expression could not be parsed. Double-check that it is "
                "typed correctly." << std::endl; 
    }
}