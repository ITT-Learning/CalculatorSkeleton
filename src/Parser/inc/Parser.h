////////////////////////////////////////////////////////////////////////////////
/**
* @file Parser.h
* @brief calculator function declarations.
*/
////////////////////////////////////////////////////////////////////////////////

#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <string>

namespace calculator
{
    struct Expression
    {
        float a;
        float b;
        char operation;
        bool valid = true;
    };

    class Parser
    {
        public:
            /**
             * @brief uses regex to ensure value is a float
             * @return isValid if it is a float
            */
            bool validateFloat(const std::string &expression);

            /**
             * @brief the main parsing function that puts all the peices together and returns an expression
             * @return an Expression object, along with whether it is valid or not
            */
            Expression parseExpression(std::string expression);

        private:
            /**
             * @brief checks if inputed char is inside of Operations array
             * @returns isValid if it is valid operator
            */
            bool validateOperator(const char &expression);
            char Operations[4] = {'+', '-', '/', '*'};

            /**
             * @brief iterates through given expression and gives back the found number
             * @returns isValid if it is valid operator
            */
            std::string findNumber(const std::string &expression);
    };
}//namespace calculator
#endif  // PARSER_H