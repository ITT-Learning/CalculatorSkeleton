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
        static constexpr char BRACKET_CLOSE = '}';
        static constexpr char BRACKET_OPEN = '{';
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
         * @brief words to quit the app
         *
         */
        static constexpr char EXIT_1[] = "q";
        static constexpr char EXIT_2[] = "e";
        static constexpr char EXIT_3[] = "exit";
        static constexpr char EXIT_4[] = "quit";

        /**
         * @brief Exit prompt
         */
        static constexpr char EXIT_PROMPT[] = "(Enter 'exit' to quit)";
        
        /**
         * @brief response given to user if input is invalid
         * 
         */
        static constexpr char INVALID_INPUT[] = "Invalid format please try again.";

        /**
         * @brief error message if args are mismateched in custom calculator
         */
        static constexpr char MISMATCHED_ARGS[] = "mismatched arguments";

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

        /**
         * @brief prompt passed to user before retrieving input from them
         *        these prompt were used for the week 4 implementation of Calculator
         *
         */
        static constexpr char W4_MAIN_PROMPT[] = "Choose a function [1-4]:\n\t[1]: Sqrt\n\t[2]: Quadratic Formula \n\t[3]: Pythagorean Theorem \n\t[4]: Add";
        static constexpr char W4_SQRT_PROMPT[] = "sqrt(x)\n please input 1 number";
        static constexpr char W4_QUAD_PROMPT[] = "ax^2 + bx + c\n please input 3 numbers seperated by spaces e.g '1 2 3'";
        static constexpr char W4_PYTH_PROMPT[] = "a^2 + b^2 = c^2\n please input 2 numbers seperated by spaces e.g '1 2'";
        static constexpr char W4_ADD2_PROMPT[] = "x + y\n please input 2 numbers seperated by spaces e.g '1 2'";

        /**
         * @brief Format strings for W4
         */
        static constexpr char W4_SQRT_FORMAT[] = "sqrt({})";
        static constexpr char W4_QUAD_FORMAT[] = "a:{} b:{} c:{} x";
        static constexpr char W4_PYTH_FORMAT[] = "sqrt({}^2 + {}^2) c";
        static constexpr char W4_ADD2_FORMAT[] = "{} + {}";
    };
} // namespace calculator


#endif // CALCULATORSTRINGS_H