///////////////////////////////////////////////////////////////////////////////
/**
 * @file  CalculatorStrings.h
 * @date  Tue, 1 June 2021
 * @brief 
 * 
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef CALCULATORSTRINGS_H
#define CALCULATORSTRINGS_H

#include <string>
namespace calculator
{
    struct CalculatorStrings
    {
        /**
         * @brief ""
         * 
         */
        static constexpr char EMPTY_STRING[] = "";

        /**
         * @brief " = "
         * 
         */
        static constexpr char EQUAL[] = " = ";

        /**
         * @brief Beginning of error message
         * 
         */
        static constexpr char ERROR_MESSAGE[] = "Error:";

        /**
         * @brief appended to error message if divide by zero is attempted
         * 
         */
        static constexpr char ERROR_MESSAGE_DIVIDE_BY_ZERO[] = " divide by zero";

        /**
         * @brief appended to error message if input is invalid
         * 
         */
        static constexpr char ERROR_MESSAGE_INVALID_INPUT[] = " invalid input";

        /**
         * @brief word to quit the app
         * 
         */
        static constexpr char EXIT[] = "exit";
        
        /**
         * @brief response given to user if input is invalid
         * 
         */
        static constexpr char INVALID_INPUT[] = "Invalid format please try again.";

        /**
         * @brief " "
         * 
         */
        static constexpr char SPACE[] = " ";

        /**
         * @brief prompt passed to user before retrieving input from them
         *        This prompt was used for the week 1 implementation of Calculator
         * 
         */
        static constexpr char W1_MAIN_PROMPT[] = "Enter two numbers, e.g. '4 10':\n(ctrl-c to exit)"; 

        /**
         * @brief prompt passed to user before retrieving input from them
         *        this prompt was used for the week 2 implementation of Calculator
         * 
         */
        static constexpr char W2_MAIN_PROMPT[] = "Input a simple math expression e.g., '5 + 5'\nValid operations are [+-/*]\n(Enter 'exit' to quit)";
    };
} // namespace calculator


#endif // CALCULATORSTRINGS_H