/**
 * @file CalculatorStrings.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-09-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef CALCULATORSTRINGS_H
#define CALCUALTORSTRING_H

#include <string>

namespace calculator
{
    class CalculatorStrings
    {
        public: 
            static constexpr char ERROR_MESSAGE_DIVIDE_BY_ZERO[] = "Error: Can not divide by zero";
            static constexpr char ERROR_MESSAGE_INVALID_INPUT[] = "Error: Invalid input";
            static constexpr char ERROR_MESSAGE_INPUT_TO_LARGE[] = "Error: One or more inputted values are too large";
            static constexpr char ERROR_MESSAGE_INPUT_TO_SMALL[] = "Error: One or more inputted values are too small";
            static constexpr char RE_ENTER_EQUATION[] = "Re-enter the math equation";
            static constexpr char ENTER_EQUATION[] = "Enter the math equation";
            static constexpr char ERROR_MESSAGE_UNKNOWN_OPERATOR[] = "Error: Unknown Operator";
            static constexpr char WELCOME_MESSAGE[] = "Welcome to the Calculator C++ learning project.";
    };
}

#endif //CALCULATOR_H