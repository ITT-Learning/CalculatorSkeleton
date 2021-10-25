#ifndef PARSER_H
#define PARSER_H

////////////////////////////////////////////////////////////////////////////////
/**
* @file CalculatorParser.h
* @brief Parser function declarations.
*/
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

#include "CalculatorStrings.h"

namespace calculator {

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
            bool validateFloat(const std::string &input);

            /**
             * @brief the main parsing function that puts all the peices together and returns an expression
             * @return an Expression object, along with whether it is valid or not
            */
            Expression parseFullEquation(const std::string &fullEquation);

            /**
             * @brief takes in input
             * @returns string of input entered
            */
            std::string getUserInput();

        private:
            char Operations[6] = {'+', '-', '/', '%', '*', 'x'};

            /**
             * @brief removes all spaces from user input
             * @returns string of input entered, without spaces
            */
            std::string removeSpaces(const std::string &input);

            /**
             * @brief checks if inputed char is inside of Operations array
             * @returns isValid if it is valid operator
            */
            bool validateOperator(const char &input);

            /**
             * @brief iterates through given expression and gives back the found number
             * @returns isValid if it is valid operator
            */
            std::string findNumber(const std::string &input);
    };
    
} //namespace calculator

#endif  // PARSER_H
