///////////////////////////////////////////////////////////////////////////////
/**
 * @file  CalculatorStrings.cpp
 * @date  Tue, 1 June 2021
 * @brief 
 * 
 */
///////////////////////////////////////////////////////////////////////////////

#include "CalculatorStrings.h"

namespace calculator
{
    const char CalculatorStrings::EMPTY_STRING[] = "";
    const char CalculatorStrings::EQUAL[] = " = ";
    const char CalculatorStrings::ERROR_MESSAGE[] = "Error:";
    const char CalculatorStrings::ERROR_MESSAGE_DIVIDE_BY_ZERO[] = " divide by zero";
    const char CalculatorStrings::ERROR_MESSAGE_INVALID_INPUT[] = " invalid input";
    const char CalculatorStrings::EXIT[] = "exit";
    const char CalculatorStrings::INVALID_INPUT[] = "Invalid format please try again.";
    const char CalculatorStrings::SPACE[] = " ";
    const char CalculatorStrings::W1_MAIN_PROMPT[] = "Enter two numbers, e.g. '4 10':\n(ctrl-c to exit)";
    const char CalculatorStrings::W2_MAIN_PROMPT[] = "Input a simple math expression e.g., '5 + 5'\nValid operations are [+-/*]\n(Enter 'exit' to quit)";
} // namespace calculator
