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
    const std::string CalculatorStrings::EMPTY_STRING = "";
    const std::string CalculatorStrings::EQUAL = " = ";
    const std::string CalculatorStrings::ERROR_MESSAGE = "Error:";
    const std::string CalculatorStrings::ERROR_MESSAGE_DIVIDE_BY_ZERO = " divide by zero";
    const std::string CalculatorStrings::ERROR_MESSAGE_INVALID_INPUT = " invalid input";
    const std::string CalculatorStrings::EXIT = "exit";
    const std::string CalculatorStrings::INVALID_INPUT = "Invalid format please try again.";
    const std::string CalculatorStrings::SPACE = " ";
    const std::string CalculatorStrings::W1_MAIN_PROMPT = "Enter two numbers, e.g. '4 10':\n(ctrl-c to exit)";
    const std::string CalculatorStrings::W2_MAIN_PROMPT = "Input a simple math expression e.g., '5 + 5'\nValid operations are [+-/*]\n(Enter 'exit' to quit)";
} // namespace calculator
