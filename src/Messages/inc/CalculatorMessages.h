#ifndef CALCULATORMESSAGES_H
#define CALCULATORMESSAGES_H

////////////////////////////////////////////////////////////////////////////////
/**
* @file CalculatorMessages.h
* @brief Error messages for Calculator.
*/
////////////////////////////////////////////////////////////////////////////////

#include <string>
namespace calculator
{
    class CalculatorMessages
    {
        public:
            /**
             * @brief equals sign
             */
            static constexpr const char *EQUALS = " = ";

            /**
             * @brief an empty space
             */
            static constexpr const char EMPTY_SPACE = ' ';

            /**
             * @brief Intro message on program start
             */
            static constexpr const char *INTRODUCTION_MESSAGE = "Let's calculate something!";

            /**
             * @brief how to use the calculator
             */
            static constexpr const char *INSTRUCTIONS_MESSAGE = "Enter a number, an operator, and another number...";

            /**
             * @brief displays after finishing calculation
             */
            static constexpr const char *RETRY_MESSAGE = "Do you have another calculation? (y/n)";

            /**
             * @brief message on program exit
             */
            static constexpr const char *OUTRO_MESSAGE = "Goodbye!";

            /**
             * @brief message on program exit
             */
            static constexpr const char *ERROR_INVALID_OPERATOR = " Invalid Operator detected";

            /**
             * @brief Beginning of error message
             */
            static constexpr const char *ERROR_MESSAGE = "Error:";

            /**
             * @brief appended to error message if divide by zero is attempted
             */
            static constexpr const char *ERROR_MESSAGE_DIVIDE_BY_ZERO = " divide by zero";
        
            /**
             * @brief appended to error message if input entered incorrectly
             */
            static constexpr const char *ERROR_MESSAGE_INVALID_INPUT = " invalid input";
    };
}//namespace calculator
   
#endif  // CALCULATOR_H