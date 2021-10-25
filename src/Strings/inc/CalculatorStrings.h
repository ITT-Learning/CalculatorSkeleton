#ifndef CALCULATORSTRINGS_H
#define CALCULATORSTRINGS_H

///////////////////////////////////////////////////////////////////////
/**
 * @file CalculatorStrings.h
<<<<<<< HEAD
 * @author your name (you@domain.com)
<<<<<<< HEAD
 * @brief 
 * @version 0.1
 * @date 2021-10-20
 * 
 * @copyright Copyright (c) 2021
=======
=======
>>>>>>> bed0e88... added formatting adjustments
 * @brief Contains all the strings
>>>>>>> d155ead... comment changes
 * 
 */
//////////////////////////////////////////////////////////////////////

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
            static constexpr char ERROR_MESSAGE_INPUT_TOO_LARGE[] = "Error: One or more inputted values are too large";
            static constexpr char ERROR_MESSAGE_INPUT_TOO_SMALL[] = "Error: One or more inputted values are too small";
            static constexpr char RE_ENTER_EQUATION[] = "Re-enter the math equation";
            static constexpr char ENTER_EQUATION[] = "Enter the math equation in the form x + y, x - y, x * y, x / y (only these operations will ensure the program to run smoothly)";
            static constexpr char ERROR_MESSAGE_UNKNOWN_OPERATOR[] = "Error: Unknown Operator";
            static constexpr char WELCOME_MESSAGE[] = "Welcome to the Calculator C++ learning project.";
            static constexpr const char EMPTY_SPACE = ' ';
            static constexpr char REPEAT_PROGRAM[] = "Would you like to run the program again? y/n";
            static constexpr char YES = 'y';
            static constexpr char ERROR_MESSAGE_INVALID_INPUT_LENGTH[] = "Error: Invalid input length";
            static constexpr char BUILDING_VECTORS[] = "\rBuilding Vectors";
            static constexpr char DISSECTING_AND_CALCULATING[] = "\rDissecting and calculating";
            static constexpr const char PLUS = '+';
            static constexpr const char MINUS = '-';
            static constexpr const char DIVIDE = '/';
            static constexpr const char TIMES = '*';
            static constexpr const char EQUAL_SIGN = '=';
            static constexpr const char *FLOAT_REGEX = R"([+-]?([0-9]+([.][0-9]*)?|[.][0-9]+))";
    };

} //namespace calculator

#endif //CALCULATORSTRINGS_H
