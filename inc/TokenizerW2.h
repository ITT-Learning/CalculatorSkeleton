/**
 * @file TokenizerW2.h
 * @author Gary Dean Jenkins (gary.jenkins@intimetec.com)
 * @brief Class for parsing operation and arthmatic statements from an input stream (istream).
 *          The TokenizerW2 is used to evaluate a single line of input. A static createTokenizer
 *          method is provided to generate multiple TokenizerW2 objects from a multi-line input stream.
 * @version 0.1
 * @date 2021-07-22
 * 
 * @copyright Copyright (c) 2021
 * @todo    1. Implement more sophisticated syntax and istream control 
 *          2. Implement consistent control using error_ for QUIT 
 * 
 */

#ifndef TOKENIZERW2_H
#define TOKENIZERW2_H

#include <iostream>

namespace calculatorw2
{
    class TokenizerW2
    {
        public:

            /**
             * @brief Static method that create a Tokenizer object from a single line of input.
             *          Multiple input lines should be handled by multiple tokenizer objects. 
             * 
             * @param IN, OUT input stream (istream) defaults to std::cin
             * @return TokenizerW2* 
             */
            static TokenizerW2* createTokenizer(std::istream& input = std::cin);


            /**
             * @brief Construct a new TokenizerW2 object
             * 
             * @param input std::string representing one line of input text
             */
            TokenizerW2(std::string input);

            /**
             * @brief Destroy the Tokenizer W 2 object
             * 
             */
            ~TokenizerW2();

            /**
             * @brief Get a control expression is intended to allow input of non-arithmatic requests
             *          and operation. Example: QUIT (or HELP in the future)
             * @note The form is a char operation followed by a descriptive string if necessary. 
             *          Ex. "q Quitting Calculator!"
             * @param OUT operation 
             * @param OUT extendedInformation 
             * @return const char* error_ value if set
             */
            const char* getControlExpression(char& operation, std::string& extendedInformation);

            /**
             * @brief Get the Math Expression from the input stream. 
             * @note The form is LEFT OPERATION RIGHT 
             *          Ex. "1 + 2" or "3.14159 / 2" or "1.25 * 4" or "7-2"
             * @param OUT left 
             * @param OUT right 
             * @param OUT operation 
             * @return const char* error_ value if set
             */
            const char* getMathExpression(double& left, double& right, char& operation);

            /**
             * @brief Get the Error object, allows calling methods to determine if there are errors.
             * 
             * @return const char* 
             */
            const char* getError();

        private:

            /**
             * @brief string for storing the input line and allowing multiple passes at parsing the input
             * 
             */
            std::string input_;

            /**
             * @brief simple string pointer for track and communicating errors
             * 
             */
            const char* error_;
    };
}

#endif //TOKENIZERW2_H