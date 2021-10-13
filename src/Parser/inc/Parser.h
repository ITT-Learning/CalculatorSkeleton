#ifndef PARSER_H
#define PARSER_H

////////////////////////////////////////////////////////////////////////////////
/**
* @file Parser.h
* @brief calculator function declarations.
*/
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>

namespace calculator
{
    struct Expression
    {
        float a;
        float b;
        char operation;
        std::string fullExpression;
        int placementIndex = 0;
    };

    struct ExpressionUnit
    {
        float number;
        char operation;
        bool valid = false;
        
    };

    class Parser
    {
        public:

            std::string originalEquation = "";
            std::string editedEquation = "";
            
            /**
             * @brief the main parsing function that puts all the peices together and returns an expression
             * @return an Expression object, along with whether it is valid or not
            */
            Expression parseFullEquation(std::vector<ExpressionUnit> &equationVector);

            /**
             * @brief takes in input
             * @returns string of input entered
            */
            std::string getUserInput();
            std::vector<ExpressionUnit> createVector(const std::string &fullEquation);

        private:
            char Operations[6] = {'+', '-', '/', '%', '*', 'x'};

            /**
             * @brief uses regex to ensure value is a float
             * @return isValid if it is a float
            */
            bool validateFloat(const std::string &input);

            /**
             * @brief removes all spaces from user input
             * @returns string of input entered, without spaces
            */
            std::string removeSpaces(const std::string &input);

            /**
             * @brief checks if inputed char is inside of Operations array
             * @returns isValid if it is valid operator
            */
            bool validateOperator(const char &expressionUnit);
            
            ExpressionUnit findOperator(std::string &input);

            /**
             * @brief iterates through given expression and gives back the found number
             * @returns isValid if it is valid operator
            */
            ExpressionUnit findNumber(std::string &editedEquation);
    };
}//namespace calculator
#endif  // PARSER_H
