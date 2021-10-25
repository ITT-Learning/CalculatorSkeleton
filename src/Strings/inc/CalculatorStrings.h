///////////////////////////////////////////////////////////////////////
/**
 * @file CalculatorStrings.h
 * @author your name (you@domain.com)
 * @brief Contains all the strings
 * 
 */
//////////////////////////////////////////////////////////////////////
#ifndef CALCULATORSTRINGS_H
#define CALCUALTORSTRING_H

#include <string>

namespace calculator {
    /**
    * @brief String interface which exposes to other components
    *
    */
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
            static constexpr char REPEAT_PROGRAM[] = "Would you like to run the program again? y/n";
            static constexpr char YES = 'y';
    };

} //namespace calculator

#endif //CALCULATORSTRINGS_H
