#ifndef PARSER_H
#define PARSER_H

////////////////////////////////////////////////////////////////////////////////
/**
* @file Parser.h
* @brief Parser function declarations.
*/
////////////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include <iostream>
#include <memory>
#include <regex>
#include <string>
#include <thread>
#include <utility>
#include <vector>

#include "CalculatorStrings.h"

namespace calculator {

struct Expression
{
    float firstNumber;
    float secondNumber;
    char operation;
    std::string fullExpression;
    int placementIndex = 0;
    bool validExpression = false;
    bool hasParenthesis = false;
};

struct ExpressionUnit
{
    static const int LENGTH_OVER_OPERATOR = 2;
    static const int PARSED_EXPRESSION_LENGTH = 3;
    float number;
    char  operation;
    bool  valid = false;
    
};

class Parser
{
    public:
        /**
         * @brief the main parsing function that puts all the peices together and returns an expression
         * @param [in] expressionUnits shared pointer of a vector passed in by reference
         * @return an Expression object, along with whether it is valid or not
        */
        Expression breakDownEquation(const std::shared_ptr<std::vector<ExpressionUnit>> &expressionUnits);

        /**
         * @brief takes in input
         * @param [in] webInput
         * @returns string of input entered
        */
        std::string getUserInput(std::string webInput);

        /**
         * @brief creates a vector out of a string
         * @param [in] fullEquation string passed in by reference 
         * @returns vector split into each unit of expression
        */
        std::pair <std::shared_ptr<std::vector<ExpressionUnit>>,bool> createVector(const std::string &fullEquation);

        /**
         * @brief returns the original equation string
         * @returns the unedited string input by user
        */
        std::string getOriginalEquation();
    private:
        std::string editedEquation_ = "";
        char        operations_[6] = {'+', '-', '/', '%', '*', 'x'};
        std::string originalEquation_ = "";

        /**
         * @brief counts parenthesis and ensures there are equal opening and closing
         * @param [in] expressionUnits shared pointer of a vector passed in by reference
         * @return isValid if there is correct number of parenthesis
        */
        bool validateParenthesis(std::shared_ptr<std::vector<ExpressionUnit>> &expressionUnits);

        /**
         * @brief uses regex to ensure value is a float
         * @param [in] input input string passed by reference
         * @return isValid if it is a float
        */
        bool validateFloat(const std::string &input);

        /**
         * @brief removes all spaces from user input
         * @param [in] input input string passed by reference
         * @returns string of input entered, without spaces
        */
        std::string removeSpaces(const std::string &input);

        /**
         * @brief checks if inputed char is inside of Operations array
         * @param [in] expressionUnit expression unit string passed by reference
         * @returns isValid if it is valid operator
        */
        bool validateOperator(const char &expressionUnit);
        
        /**
         * @brief finds the operator in the string input
         * @param [in] input input string passed by reference  
         * @return ExpressionUnit 
         */
        ExpressionUnit findOperator(std::string &input);

        /**
         * @brief iterates through given expression and gives back the found number
         * @param [in] editedEquation edited equation string passed by reference
         * @returns isValid if it is valid operator
        */
        ExpressionUnit findNumber(std::string &editedEquation);
};
    
} //namespace calculator

#endif  // PARSER_H
