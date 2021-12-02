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
 * @param isValid bool if expression is valid
*/
struct Expression
{
    float number1;
    float number2;
    char  operation;
    int   placementIndex = 0;
    bool  isValid = false;
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
    int unitLength = 1;
};

class Parser
{
    public:
        /**
         * @brief the main parsing function that puts all the pieces together and returns an expression
         * @param [in] equations a pointer to a vector containing each equation piece
         * @return an Expression object, along with whether it is valid or not
        */
        Expression breakDownEquation(const std::shared_ptr<std::vector<ExpressionUnit>> &equations);

        /**
         * @brief sets the original equation and returns the original without spaces
         * @param [in] input is the submitted equation string
         * @returns original equation without spaces after being run through removeSpaces function
        */
        std::string processUserInput(std::string input);

        /**
         * @brief creates a vector out of a string
         * @param [in] fullEquation this is the spaceless equation string returned from getUserInput
         * @returns expressionUnits
        */
        std::pair <std::shared_ptr<std::vector<ExpressionUnit>>,bool> getValidParsedEquationUnits(const std::string &fullEquation);

        /**
         * @brief returns the original equation string
         * @returns originalEquation_ (the unedited string input by user)
        */
        std::string getOriginalEquation();

    private:
        const int EXPRESSION_SIZE = 3;
        std::string editedEquation_ = "";
        std::string originalEquation_ = "";

        /**
         * @brief counts parenthesis and ensures there are equal opening and closing
         * @param equations 
         * @returns true if openParenthesisCount equals closeParenthesisCount, otherwise false
        */
        bool validateParenthesis(std::shared_ptr<std::vector<ExpressionUnit>> &equations);

        /**
         * @brief uses regex to ensure value is a float
         * @param [in] floatString a string that wil be converted into a float, and validated with regex
         * @return true if it is a float
        */
        bool validateFloat(const std::string &floatString);

        /**
         * @brief removes all spaces from user input
         * @param [in] userInput the entered user input from getUserInput function
         * @returns string created from userImput without spaces
        */
        std::string removeSpaces(const std::string &userInput);

        /**
         * @brief checks if inputed char is inside of Operations array
         * @param [in] operation char operator from findOperator function
         * @returns bool for if operator is valid 
        */
        bool validateOperator(const char operation);
        
        /**
         * @brief creates an expression unit for an operator
         * @param [in] operation a char that will be evaluated and put into an expression unit
         * @returns expressionUnit with an operator value
         * */
        ExpressionUnit getOperatorExpressionUnit(char operation);

        /**
         * @brief creates an expression unit for a number
         * @param [in] editedEquation the current editedEquation string, it will get edited in this function
         * @returns expressionUnit with float value
        */
        ExpressionUnit getNumberExpressionUnit(std::string &editedEquation);

        /**
         * @brief used to initially set the editedEquation_ variable 
         * @param [in] fullEquation the equation without spaces
        */
        void setEditedEquation(const std::string &fullEquation);

        /**
         * @brief , edits the editedEquation_ variable
         * @param [in] editAmmount overloaded to accept the ammount to remove from editedEquation
        */
        void setEditedEquation(int editAmmount);

        /**
         * @brief looks at parenthesis and returns whether or not parser would be looking for a number or not
         * @param [in] parenthesis char, a either '(' or ')'
         * @return false if '(' , return true if ')'  
        */
        bool checkParenthesis(char parenthesis);


};

} //namespace calculator

#endif  // PARSER_H
