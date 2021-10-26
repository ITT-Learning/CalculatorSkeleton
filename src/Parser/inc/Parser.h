#ifndef PARSER_H
#define PARSER_H

////////////////////////////////////////////////////////////////////////////////
/**
* @file Parser.h
* @brief calculator function declarations.
*/
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <memory>
#include <string>
#include <vector>

namespace calculator {

    /**
    * @brief Parser interface which exposes to other components
    */

     /**
     * @brief struct for Expression Object
     * @param number1 first float in expression
     * @param number2 second float in expression
     * @param operation opearation char in expression
     * @param placementIndex index of where expression unit starts 
     * @param isValidExpression bool if expression is valid
    */
    struct Expression
    {
        float number1;
        float number2;
        char  operation;
        int   placementIndex = 0;
        bool  isValidExpression = false;
    };

     /**
     * @brief struct for Expression Object
     * @param number float if expression unit is a number
     * @param operation char if expression unit is an operation
     * @param isValid bool if expression object is valid
    */
    struct ExpressionUnit
    {
        float number;
        char  operation;
        bool  isValid = false;
    };

    class Parser
    {
        public:
            /**
             * @brief the main parsing function that puts all the pieces together and returns an expression
             * @param [in] equationVector a pointer to a vector containing each equation piece
             * @return an Expression object, along with whether it is valid or not
            */
            Expression breakDownEquation(const std::shared_ptr<std::vector<ExpressionUnit>> &equationVector);

            /**
             * @brief takes in input from cin and edits it, also saves it to originalEquation_
             * @returns userInput after it's sent through removeSpaces function
            */
            std::string getUserInput();

            /**
             * @brief creates a vector out of a string
             * @param [in] fullEquation this is the spaceless equation string returned from getUserInput
             * @returns completedVector
            */
            std::pair <std::shared_ptr<std::vector<ExpressionUnit>>,bool> createVector(const std::string &fullEquation);

            /**
             * @brief returns the original equation string
             * @returns originalEquation_ (the unedited string input by user)
            */
            std::string getOriginalEquation();

        private:
            std::string editedEquation_ = "";
            std::string originalEquation_ = "";

            /**
             * @brief counts parenthesis and ensures there are equal opening and closing
             * @param equationVector 
             * @return openParenthesisCount == closeParenthesisCount
            */
            bool validateParenthesis(std::shared_ptr<std::vector<ExpressionUnit>> &equationVector);

            /**
             * @brief uses regex to ensure value is a float
             * @param [in] floatString a string of a float from findNumber function
             * @return true if it is a float
            */
            bool validateFloat(const std::string &input);

            /**
             * @brief removes all spaces from user input
             * @param [in] userInput the entered user input from getUserInput function
             * @returns string created from userImput without spaces
            */
            std::string removeSpaces(const std::string &input);

            /**
             * @brief checks if inputed char is inside of Operations array
             * @param [in] operation char operator from findOperator function
             * @returns bool for if operator is valid 
            */
            bool validateOperator(const char &expressionUnit);
            
            /**
             * @brief creates an expression unit for an operator and edits the editedString
             * @param [in] editedEquation the current editedEquation string
             * @returns expressionUnit with an operator value
             * */
            ExpressionUnit findOperator(std::string &editedEquation);

            /**
             * @brief creates an expression unit for a number and edits the editedString
             * @param [in] editedEquation_ the current editedEquation string
             * @returns expressionUnit with float value
            */
            ExpressionUnit findNumber(std::string &editedEquation);
    };

}//namespace calculator

#endif  // PARSER_H
