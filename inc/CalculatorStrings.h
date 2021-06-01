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
        static const std::string EMPTY_STRING;

        /**
         * @brief " = "
         * 
         */
        static const std::string EQUAL;

        /**
         * @brief Beginning of error message
         * 
         */
        static const std::string ERROR_MESSAGE;

        /**
         * @brief appended to error message if divide by zero is attempted
         * 
         */
        static const std::string ERROR_MESSAGE_DIVIDE_BY_ZERO;

        /**
         * @brief appended to error message if input is invalid
         * 
         */
        static const std::string ERROR_MESSAGE_INVALID_INPUT;

        /**
         * @brief word to quit the app
         * 
         */
        static const std::string EXIT;
        
        /**
         * @brief response given to user if input is invalid
         * 
         */
        static const std::string INVALID_INPUT;

        /**
         * @brief " "
         * 
         */
        static const std::string SPACE;

        /**
         * @brief prompt passed to user before retrieving input from them
         *        This prompt was used for the week 1 implementation of Calculator
         * 
         */
        static const std::string W1_MAIN_PROMPT; 

        /**
         * @brief prompt passed to user before retrieving input from them
         *        this prompt was used for the week 2 implementation of Calculator
         * 
         */
        static const std::string W2_MAIN_PROMPT;
    };
} // namespace calculator


#endif // CALCULATORSTRINGS_H