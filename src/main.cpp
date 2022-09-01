////////////////////////////////////////////////////////////////////////////
/**
 *  @file   main.cpp
 *  @date   Fri April 16 2021
 *  @brief  Entry Point of Calculator
 */
////////////////////////////////////////////////////////////////////////////

#include "Calculator.h"
#include "CalcHistory.h"
#include <iostream>
#include <string>
#include <math.h>

int findPrecisionFor(int number, int decimalDigits = 4)
{
    int baseLog = (int)log10(std::abs(number));
    int effectiveLog = std::max(baseLog + 1 + decimalDigits, baseLog * - 1);
    return effectiveLog;
};

void printHistory(CalcHistory &history)
{
    std::cout << "\n\n" << history << "\n\n";
};

void showHelpText()
{
    std::cout << "\n\n"
        << "           Calculator"
        << "\n\n"
        << "      supports + - * / ( )\n"
        << "    enter history for history\n"
        << "       enter quit to quit\n"
        << "  enter help for this dialogue\n\n";
};

void repl()
{
    CalcHistory history;
    while(true)
    {
        std::string equation;
        std::cout << "> ";
        getline(std::cin, equation);
        if(equation.substr(0, 4) == "quit")
            break;
        if(equation.substr(0,4) == "help")
            showHelpText();
        if(equation.substr(0, 7) == "history")
        {
            printHistory(history);
            continue;
        }
        equation = Calculator::sanitizeString(equation);
        if(equation.empty())
        {
            std::cout << "\nNo valid command or equation found.\n\n";
            continue;
        }
        double result = Calculator::calculate(equation);
        std::cout.precision(findPrecisionFor(result));
        std::cout << "= " << result << "\n\n";
        history.addEntry(equation, result);
    }
};

int main(int argc, char* argv[]) 
{
    showHelpText();
    repl();
    return 0;
};