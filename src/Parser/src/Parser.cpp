////////////////////////////////////////////////////////////////////////////////
/**
* @file Parser.cpp
* @brief Function definitions for Parser
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

#include "CalculatorMessages.h"
#include "Parser.h"


namespace calculator {

// ***************************************************************************** /
// ***************** Parser public methods ************************************* /
// ***************************************************************************** /

std::pair <std::shared_ptr<std::vector<ExpressionUnit>>,bool> Parser::getValidParsedEquationUnits(const std::string &fullEquation)
{ 
    std::shared_ptr<std::vector<ExpressionUnit>> equations;
    equations = std::make_shared<std::vector<ExpressionUnit>>();
    ExpressionUnit currentUnit;
    bool isCheckingForNumber = true;
    bool isValid = true;

    std::this_thread::sleep_for(std::chrono::milliseconds(300)); //sleeping to show off thread in use

    setEditedEquation(fullEquation);

    while (editedEquation_.length() > 0)
    {
        if (editedEquation_.at(0) == CalculatorMessages::OPEN_PARENTHESIS || editedEquation_.at(0) == CalculatorMessages::CLOSE_PARENTHESIS)
        {
            currentUnit.operation = editedEquation_.at(0);
            currentUnit.isValid = true;
            isCheckingForNumber = checkParenthesis(currentUnit.operation);
        }
        else
        {
            isCheckingForNumber ? currentUnit = getNumberExpressionUnit(editedEquation_) : currentUnit = getOperatorExpressionUnit(editedEquation_.at(0));
        }
        
        if(currentUnit.isValid)
        {
            setEditedEquation(currentUnit.unitLength);
            isCheckingForNumber = !isCheckingForNumber;
            equations->push_back(currentUnit);
        }
        else
        {
            isValid = false;
            break;
        }
    }

    if(isValid && equations->size() < EXPRESSION_SIZE) // ensuring an expressionUnit vector has at least 3 units
    {
        std::cout << std::endl;
        std::cout << CalculatorMessages::ERROR_MESSAGE << CalculatorMessages::ERROR_MESSAGE_INVALID_INPUT_LENGTH << std::endl;
        isValid = false;
    }

    if (isValid)
    {
        isValid = validateParenthesis(equations);
    }

    std::pair < std::shared_ptr<std::vector<ExpressionUnit>>,bool> expressionUnits (equations, isValid);

    return expressionUnits;
}

Expression Parser::breakDownEquation(const std::shared_ptr<std::vector<ExpressionUnit>> &equations)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(800)); //sleeping to show off thread in use
    
    char lastParenthesis = CalculatorMessages::OPEN_PARENTHESIS;  
    size_t startingPoint = 0;
    size_t endingPoint = equations->size();

    for (size_t i = 0; i < equations->size(); i++) //find parenthesis that open then close
    {
        if (equations->at(i).operation == CalculatorMessages::OPEN_PARENTHESIS)
        {
            startingPoint = i;
        }

        if (equations->at(i).operation == CalculatorMessages::CLOSE_PARENTHESIS && lastParenthesis == CalculatorMessages::OPEN_PARENTHESIS)
        {
            endingPoint = i;
            equations->erase(equations->begin() + startingPoint); //erase parenthesis
            equations->erase(equations->begin() + (endingPoint - 1));
            endingPoint = endingPoint - 2;
            break;
        }

        if (equations->at(i).operation == CalculatorMessages::OPEN_PARENTHESIS || equations->at(i).operation == CalculatorMessages::CLOSE_PARENTHESIS)
        {
            lastParenthesis = equations->at(i).operation;
        }
    }

    char priorityOperator;
    Expression parsedExpression;

    if ((startingPoint + (EXPRESSION_SIZE - 1)) <= endingPoint) // check to ensure user didn't enter something like "(1+)"
    {
        for (size_t i = startingPoint; i < endingPoint; i++) //find operator in order
        {
            if (equations->at(i).isValid)
            {
                parsedExpression.isValid = true;
                if (equations->at(i).operation == CalculatorMessages::DIVIDE || equations->at(i).operation == CalculatorMessages::MULTIPLY)
                {
                    priorityOperator = equations->at(i).operation;
                    parsedExpression.placementIndex = i - 1;
                    break;
                }
                
                if (equations->at(i).operation == CalculatorMessages::SUBTRACT || equations->at(i).operation == CalculatorMessages::ADD)
                {
                    if(priorityOperator != CalculatorMessages::SUBTRACT  && priorityOperator != CalculatorMessages::ADD)
                    {
                        priorityOperator = equations->at(i).operation;
                        parsedExpression.placementIndex = i - 1;
                    }

                    continue;
                }
            }
            else
            {
                parsedExpression.isValid = false;
                break;
            }
        }
    }
    else
    {
        parsedExpression.isValid = false;
        equations->erase(equations->begin() + startingPoint, equations->begin() + endingPoint);
    }

    if (parsedExpression.isValid)
    {
        parsedExpression.operation = priorityOperator; //set up expression Object
        parsedExpression.number1 = equations->at(parsedExpression.placementIndex).number; // start at the first unit of expression
        parsedExpression.number2 = equations->at(parsedExpression.placementIndex + (EXPRESSION_SIZE - 1)).number; // find the next number unit by adding 2 (skipping over the operator)
        equations->erase(
        equations->begin() + parsedExpression.placementIndex, //erase starting at the first number
        equations->begin() + parsedExpression.placementIndex + EXPRESSION_SIZE); //delete 3 units (the length of a parsed expression)
    }

    return parsedExpression;
}

std::string Parser::getUserInput()
{
    std::cout << CalculatorMessages::INTRODUCTION_MESSAGE << std::endl;
    std::cout << CalculatorMessages::INSTRUCTIONS_MESSAGE << std::endl;

    std::string userInput;

    getline(std::cin, userInput);

    if (userInput == CalculatorMessages::EMPTY_STRING)
    {
        getline(std::cin, userInput);
    }

    originalEquation_ = userInput;
    
    return removeSpaces(userInput); 
}

std::string Parser::getOriginalEquation()
{
    return originalEquation_;
}

// ***************************************************************************** /
// ***************** Parser private methods ************************************ /
// ***************************************************************************** /

bool Parser::validateParenthesis(std::shared_ptr<std::vector<ExpressionUnit>> &equations)
{
    int openParenthesisCount = 0;
    int closeParenthesisCount = 0;
    
    for (size_t i = 0; i < equations->size(); i++) //find parenthesis
    {
        if (equations->at(i).isValid)
        {
            if (equations->at(i).operation == CalculatorMessages::OPEN_PARENTHESIS)
            {
                openParenthesisCount++;
            }

            if (equations->at(i).operation == CalculatorMessages::CLOSE_PARENTHESIS)
            {
                closeParenthesisCount++;
            }
        }
    }

    if (openParenthesisCount != closeParenthesisCount)
    {
        std::cout << CalculatorMessages::ERROR_MESSAGE << CalculatorMessages::ERROR_INVALID_OPERATOR << std::endl;
    }

    return openParenthesisCount == closeParenthesisCount;
}

ExpressionUnit Parser::getOperatorExpressionUnit(char operation)
{
    ExpressionUnit expressionUnit;
    expressionUnit.isValid = validateOperator(operation);
    
    if (operation == CalculatorMessages::MULTIPLY2 || operation == CalculatorMessages::MULTIPLY3)
    {
        expressionUnit.operation = CalculatorMessages::MULTIPLY;
    }
    else if (operation == CalculatorMessages::DIVIDE2)
    {
        expressionUnit.operation = CalculatorMessages::DIVIDE;
    }
    else 
    {
        expressionUnit.operation = operation;
    }

    return expressionUnit;
}

bool Parser::validateOperator(const char operation)
{
    bool isValid = false;

    for (size_t i = 0; CalculatorMessages::POSSIBLE_OPERATIONS[i] != '\0'; i++)
    {
        if (operation == CalculatorMessages::POSSIBLE_OPERATIONS[i])
        {
            isValid = true;
        }
    }

    if (!isValid)
    {
        std::cout << CalculatorMessages::ERROR_MESSAGE << CalculatorMessages::ERROR_INVALID_OPERATOR << std::endl;
    }

    return isValid;
}

bool Parser::validateFloat(const std::string &floatString)
{
    bool isValid =false;
    static const std::regex floatRegex{CalculatorMessages::FLOAT_REGEX};

    if (std::regex_match(floatString, floatRegex))
    {
        isValid = true;
    }
    else
    {
        std::cout << CalculatorMessages::ERROR_MESSAGE << CalculatorMessages::ERROR_MESSAGE_INVALID_NUMBER << std::endl;
    }

    return isValid;
}

ExpressionUnit Parser::getNumberExpressionUnit(std::string &editedEquation)
{
    std::string numberString = CalculatorMessages::EMPTY_STRING;

    for (auto currentChar : editedEquation)
    {
        if (currentChar == CalculatorMessages::SUBTRACT && numberString.length() == 0)
        {
            numberString += currentChar;
        }
        else if (currentChar == CalculatorMessages::PERIOD)
        {
            numberString += currentChar;
        }
        else if (std::isdigit(currentChar))
        {
            numberString += currentChar;
        }
        else
        {
            break;
        }      
    }

    ExpressionUnit expressionUnit;
    expressionUnit.isValid = validateFloat(numberString);
    if (expressionUnit.isValid)
    {
        expressionUnit.number = std::stof(numberString);
        expressionUnit.unitLength = numberString.length();
    }

    return expressionUnit;
}

std::string Parser::removeSpaces(const std::string &userInput)
{
    std::string fullEquation;
    for (auto currentChar : userInput)
    {
        if(currentChar == CalculatorMessages::EMPTY_SPACE)
        {
            continue;
        }
        else
        {
            fullEquation += currentChar;
        }
    }

    return fullEquation;
}

bool Parser::checkParenthesis(char parenthesis)
{
    bool isCheckingForNumber;

    if (parenthesis == CalculatorMessages::OPEN_PARENTHESIS)
    {
        isCheckingForNumber = false;
    }

    if (parenthesis == CalculatorMessages::CLOSE_PARENTHESIS)
    {
        isCheckingForNumber = true;
    }

    return isCheckingForNumber;
}

void Parser::setEditedEquation(const std::string &fullEquation)
{
    editedEquation_ = fullEquation;
}

void Parser::setEditedEquation(int editAmmount)
{
    editedEquation_ = editedEquation_.erase(0, editAmmount);
}

} //namespace calculator
