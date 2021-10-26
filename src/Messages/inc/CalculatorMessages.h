#ifndef CALCULATORMESSAGES_H
#define CALCULATORMESSAGES_H

////////////////////////////////////////////////////////////////////////////////
/**
* @file CalculatorMessages.h
* @brief Error messages for Calculator.
*/
////////////////////////////////////////////////////////////////////////////////

#include <string>
namespace calculator {
    class CalculatorMessages
    {
        public:
            /**
             * @brief available operations
             */
            static constexpr const char *OPERATIONS = "+-/%*x";

            /**
             * @brief equals sign
             */
            static constexpr const char *EQUALS = " = ";

            /**
             * @brief an empty space
             */
            static constexpr const char EMPTY_SPACE = ' ';

            /**
             * @brief an empty space
             */
            static constexpr const char PERIOD = '.';

            /**
             * @brief an empty space
             */
            static constexpr const char OPEN_PARENTHESIS = '(';

            /**
             * @brief an empty space
             */
            static constexpr const char CLOSE_PARENTHESIS = ')';

            /**
             * @brief an empty space
             */
            static constexpr const char *EMPTY_STRING = "";

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
            static constexpr const char *ERROR_INVALID_OPERATOR = " Invalid operator detected";

            /**
             * @brief Beginning of error message
             */
            static constexpr const char *ERROR_MESSAGE = "Error:";

            /**
             * @brief appended to error message if expression gets through vector but ends up as an invalid expression after 
             */
            static constexpr const char *ERROR_MESSAGE_INVALID_EXPRESSION = "Invalid expression detected";

            /**
             * @brief appended to error message if divide by zero is attempted
             */
            static constexpr const char *ERROR_MESSAGE_DIVIDE_BY_ZERO = " divide by zero";
        
            /**
             * @brief appended to error message if number entered incorrectly
             */
            static constexpr const char *ERROR_MESSAGE_INVALID_NUMBER = " Invalid number detected";

            /**
             * @brief appended to error message if input entered is at least three calculation units
             */
            static constexpr const char *ERROR_MESSAGE_INVALID_INPUT_LENGTH = " Invalid input length";

            /**
             * @brief used when creating vector
             */
            static constexpr const char *CREATING_VECTOR = "\rCreating Vector...";

            /**
             * @brief used when breaking down equation and calculating
             */
            static constexpr const char *BREAKING_DOWN_AND_CALCULATING = "\rBreaking Down Equation / Calculating...";
            
            /**
             * @brief used for checking if a value is a float
             */
            static constexpr const char *FLOAT_REGEX = R"([+-]?([0-9]+([.][0-9]*)?|[.][0-9]+))";    
    };

}//namespace calculator

#endif  // CALCULATOR_H
