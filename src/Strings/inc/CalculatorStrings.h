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
        static constexpr char BRACKET_OPEN  = '{';
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
        static constexpr char EXIT_PROMPT[] = "([e]xit or [q]uit to go back)";
        
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
         * @brief Message given if no history is found
         */
        static constexpr char NO_HISTORY[] = "No history found.";

        /**
         * @brief Matches an add or subtract subexpression in a compound expression
         *        e.g., "1 + 2 - 3 - -4" will match "1 + 2" and "3 - -4", note, 2 - 3 is not caught because 2 is part of another match
         *        [-]? matches 0/1 '-' this let's us catch negative numbers
         *        [0-9]+ matches at least 1 number
         *        [ ]* allows any amount of whitespace between number and operator
         *        [+-] matches + or -
         */
        static constexpr char REGEX_PATTERN_ADD_SUBTRACT_EXPRESSION[] = "[-]?[0-9]+[ ]*[+-][ ]*[-]?[0-9]+";

        /**
         * @brief Matches an multiply or divide subexpression in a compound expression
         *        e.g., "1 * 2 / 3 / -4" will match "1 * 2" and "3 / -4", note, 2 / 3 is not caught because 2 is part of another match
         *        [-]? matches 0/1 '-' this let's us catch negative numbers
         *        [0-9]+ matches at least 1 number
         *        [ ]* allows any amount of whitespace between number and operator
         *        [* /] matches * or /
         */
        static constexpr char REGEX_PATTERN_MULTIPLY_DIVIDE_EXPRESSION[] = "[-]?[0-9]+[ ]*[*/][ ]*[-]?[0-9]+";

        /**
         * @brief Get's the operator from the inside of the expression
         *        e.g., "-1 + 1" will match "+"
         *        this is complicated by the fact that we can't match the '-' if it is a negative number
         *        ((?![-]?[0-9]+[ ]*)[-]) - this bit is to make sure we get the minus operator, not a negative number
         *            (?!...) - means needed to match, but not included in the matched part; this will match the number before the subtraction
         *            [-]?    - says a number can be negative (allows 0 or 1 '-') in front
         *            [0-9]+  - the number part, 1 or more numbers
         *            [ ]*    - allows 0 or more ' ' for whitespace
         *        |([+* /] - |(pipe) is logical-or and [+* /] is match anyone of those characters (spaces added for comment)
         *            Subtraction is the only special case so this bit should be straightforward as far as regex goes
         */
        static constexpr char REGEX_PATTERN_OPERATOR_FROM_SIMPLE_EXPRESSION[] = "((?![-]?[0-9]+[ ]*)[-])|([+*/])";

        /**
         * @brief Find the variable and value pairs
         *        e.g. "a = 10"
         *        [a-zA-Z]{1} - match just 1 character
         *        [ ]?        - allow 0 or 1 space
         *        [=]         - expect an equal sign
         *        [-]         - allow negative numbers
         *        [0-9]+      - and then any amount of numbers
         *
         */
        static constexpr char REGEX_PATTERN_VARIABLE_VALUE_PAIR[] = "[a-zA-Z]{1}[ ]?[=][ ]?[-]?[0-9]+";
        /**
         * @brief Used for regex replace, takes the match and surrounds it with []
         *        this is needed because + and * are special characters in regex surrounding them with [] is like escaping them
         *        e.g. "10 + 10" with a match of "+" will be "10 [+] 10"
         */
        static constexpr char REGEX_PATTERN_REPLACE_SURROUND_WITH_BRACKET[] = "[$&]";

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
        static constexpr char W2_MAIN_PROMPT[] = "Input a simple math expression e.g., '5 + 5'\nValid operations are [+-/*]";

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

        /**
         * @brief Prompts for Week 5 Application Run
         */
        static constexpr char W5_MAIN_PROMPT[]     = "[1] Compound Expression\te.g.,'10 - 3 + 5 * -8'\n[2] Variable Expression\te.g.,'a = 10, b = 3' > 'a + b / a'";
        static constexpr char W5_COMPOUND_PROMPT[] = "Enter a compound expression \ne.g., '10 + 10 - 3 * 100'";
        static constexpr char W5_VARIABLE_PROMPT[] = "Enter your variable with values\ne.g., 'a = 10, b = 3, x = 9'";
        static constexpr char W5_VARCOMP_PROMPT[]  = "Enter the compound expression with variables\ne.g., 'a + b / a + 100 * x'\nYours variables are: ";

        /**
         * @brief Prompts for Week 6 Application Run
         */
        static constexpr char W6_HISTORY_PROMPT[] = "[w] to move up, [s] to move down, or number [0+] to get by index";
        static constexpr char W6_MAIN_PROMPT[]    = "[1] Simple Calculators\n[2] Compound Calculators\n[3] History";

    };
} // namespace calculator


#endif // CALCULATORSTRINGS_H