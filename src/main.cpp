////////////////////////////////////////////////////////////////////////////
/**
 *  @file   main.cpp
 *  @date   Fri April 16 2021
 *  @brief  Entry Point of Calculator
 */
////////////////////////////////////////////////////////////////////////////

#include "Calculator.h"
#include <iostream>
#include <string>
#include <math.h>

int main(int argc, char* argv[]) 
{
    std::string equation;
    std::cout << "\n\n\tCalculator\n\n"
        << "  supports + - * / ( )\n"
        << "  enter no input to quit\n\n";
    while(true)
    {
        std::cout << "> ";
        getline(std::cin, equation);
        if(equation.empty())
            break;
        double result = Calculator::calculate(equation);
        int resultLog = (int)log10(result);
        int effectiveLog = std::max(resultLog + 5, resultLog * - 1);
        std::cout.precision(effectiveLog);
        std::cout << "= " << result << "\n\n";
    }
    return 0;
};