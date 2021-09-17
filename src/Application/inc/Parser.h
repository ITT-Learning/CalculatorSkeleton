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
    enum class Operations : char
    {
        ADD = '+',
        SUBTRACT = '-',
        MULTIPLY = '*',
        DIVIDE = "/"
    };

    struct Expression
    {
        float a;
        float b;
        Operations operation;
    }

    class Parser
    {
        public:
            static bool validateExpression(const std::string &expression);

            static Expression parseExpression(const std::string &expression);
        private:
            static float findNumber(std::string &expression)
            {
                //check is valid number
                // expression = -1.03+1.05
                // return -1.03
                //change expression 
                // expression = +1.05
            }
            static Operations findOperation(std::string &expression);
    };
}//namespace calculator
#endif  // PARSER_H