////////////////////////////////////////////////////////////////////////////
/**
 *  @file   main.cpp
 *  @date   Fri April 16 2021
 *  @brief  Entry Point of Calculator
 */
////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>

#include "Symbol.h"

int main() 
{
    std::cout << "Welcome to the Calculator C++ learning project." << std::endl;
    std::cout << "Please enter two numbers to add: " << std::endl;
    std::vector<calculator::Symbol<int>> symbols{
            calculator::Symbol<int>{'a'}, calculator::Symbol<int>{'b'}};

    for(auto &s : symbols)
    {
        s.bindFromStreams(std::cin, std::cout);
    }
    std::cout << symbols[0].getValue() << " + " << symbols[1].getValue() <<
            " = " << symbols[0].getValue() + symbols[1].getValue() << std::endl;
    std::cout << symbols[0].getValue() << " * " << symbols[1].getValue() <<
            " = " << symbols[0].getValue() * symbols[1].getValue() << std::endl;
    std::cout << symbols[0].getValue() << " / " << symbols[1].getValue() <<
            " = " << symbols[0].getValue() / symbols[1].getValue() << std::endl;
    std::cout << symbols[0].getValue() << " % " << symbols[1].getValue() <<
            " = " << symbols[0].getValue() % symbols[1].getValue() << std::endl;

    return 0;
}