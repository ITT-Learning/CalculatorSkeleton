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

std::pair <std::shared_ptr<std::vector<ExpressionUnit>>,bool> Parser::createVector(const std::string &fullEquation)
{ 
    editedEquation_ = fullEquation;
    std::shared_ptr<std::vector<ExpressionUnit>> equationVector;
    equationVector = std::make_shared<std::vector<ExpressionUnit>>();
    ExpressionUnit currentUnit;
    bool checkingNumber = true;
    bool validVector = true;

    std::this_thread::sleep_for(std::chrono::milliseconds(300)); //sleeping to show off thread in use

    while (editedEquation_.length() > 0)
    {
        if (editedEquation_.at(0) == CalculatorMessages::OPEN_PARENTHESIS || editedEquation_.at(0) == CalculatorMessages::CLOSE_PARENTHESIS)
        {
            if (editedEquation_.at(0) == CalculatorMessages::OPEN_PARENTHESIS)
            {
                checkingNumber = false;
            }

            if (editedEquation_.at(0) == CalculatorMessages::CLOSE_PARENTHESIS)
            {
                checkingNumber = true;
            }

            currentUnit.operation = editedEquation_.at(0);
            currentUnit.isValid = true;
            editedEquation_ = editedEquation_.erase(0, 1);
        }
        else
        {
            checkingNumber ? currentUnit = findNumber(editedEquation_) : currentUnit = findOperator(editedEquation_);
        }
        
        if(currentUnit.isValid)
        {
            checkingNumber = !checkingNumber;
            equationVector->push_back(currentUnit);
        }
        else
        {
            validVector = false;
            break;
        }
    }

    if(validVector && equationVector->size() < 3) // ensuring an expressionUnit vector has at least 3 units
    {
        std::cout << std::endl;
        std::cout << CalculatorMessages::ERROR_MESSAGE << CalculatorMessages::ERROR_MESSAGE_INVALID_INPUT_LENGTH << std::endl;
        validVector = false;
    }

    if (validVector)
    {
        validVector = validateParenthesis(equationVector);
    }

    std::pair < std::shared_ptr<std::vector<ExpressionUnit>>,bool> completedVector (equationVector, validVector);

    return completedVector;
}

Expression Parser::breakDownEquation(const std::shared_ptr<std::vector<ExpressionUnit>> &equationVector)
{
    Expression parsedExpression;
    char       importantOperator;
    char       lastParenthesis = CalculatorMessages::OPEN_PARENTHESIS;
    size_t     startingPoint = 0;
    size_t     endingPoint = equationVector->size();
    
    std::this_thread::sleep_for(std::chrono::milliseconds(800)); //sleeping to show off thread in use

    for (size_t i = 0; i < equationVector->size(); i++) //find parenthesis that open then close
    {
        if (equationVector->at(i).operation == CalculatorMessages::OPEN_PARENTHESIS)
        {
            startingPoint = i;
        }

        if (equationVector->at(i).operation == CalculatorMessages::CLOSE_PARENTHESIS && lastParenthesis == CalculatorMessages::OPEN_PARENTHESIS)
        {
            endingPoint = i;
            equationVector->erase(equationVector->begin() + startingPoint); //erase parenthesis
            equationVector->erase(equationVector->begin() + (endingPoint - 1));
            endingPoint = endingPoint - 2;
            break;
        }

        if (equationVector->at(i).operation == CalculatorMessages::OPEN_PARENTHESIS || equationVector->at(i).operation == CalculatorMessages::CLOSE_PARENTHESIS)
        {
            lastParenthesis = equationVector->at(i).operation;
        }
    }

    if ((startingPoint + 2) <= endingPoint) // check to ensure user didn't enter something like "(1+)"
    {
        for (size_t i = startingPoint; i < endingPoint; i++) //find operator in order
        {
            if (equationVector->at(i).isValid)
            {
                parsedExpression.isValidExpression = true;
                if (equationVector->at(i).operation == CalculatorMessages::OPERATIONS[2] || 
                    equationVector->at(i).operation == CalculatorMessages::OPERATIONS[3] || 
                    equationVector->at(i).operation == CalculatorMessages::OPERATIONS[4] || 
                    equationVector->at(i).operation == CalculatorMessages::OPERATIONS[5])
                {
                    importantOperator = equationVector->at(i).operation;
                    parsedExpression.placementIndex = i - 1;
                    break;
                }
                
                if (equationVector->at(i).operation == CalculatorMessages::OPERATIONS[1] || equationVector->at(i).operation == CalculatorMessages::OPERATIONS[0])
                {
                    if(importantOperator != CalculatorMessages::OPERATIONS[1]  && importantOperator != CalculatorMessages::OPERATIONS[0])
                    {
                        importantOperator = equationVector->at(i).operation;
                        parsedExpression.placementIndex = i - 1;
                    }

                    continue;
                }
            }
            else
            {
                parsedExpression.isValidExpression = false;
                break;
            }
        }
    }
    else
    {
        parsedExpression.isValidExpression = false;
        equationVector->erase(equationVector->begin() + startingPoint, equationVector->begin() + endingPoint);
    }

    if (parsedExpression.isValidExpression)
    {
        parsedExpression.operation = importantOperator; //set up expression Object
        parsedExpression.number1 = equationVector->at(parsedExpression.placementIndex).number; // start at the first unit of expression
        parsedExpression.number2 = equationVector->at(parsedExpression.placementIndex + 2).number; // find the next number unit by adding 2 (skipping over the operator)
        equationVector->erase(
        equationVector->begin() + parsedExpression.placementIndex, //erase starting at the first number
        equationVector->begin() + parsedExpression.placementIndex + 3); //delete 3 units (the length of a parsed expression)
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

bool Parser::validateParenthesis(std::shared_ptr<std::vector<ExpressionUnit>> &equationVector)
{
    int openParenthesisCount = 0;
    int closeParenthesisCount = 0;
    
    for (size_t i = 0; i < equationVector->size(); i++) //find parenthesis
    {
        if (equationVector->at(i).isValid)
        {
            if (equationVector->at(i).operation == CalculatorMessages::OPEN_PARENTHESIS)
            {
                openParenthesisCount++;
            }

            if (equationVector->at(i).operation == CalculatorMessages::CLOSE_PARENTHESIS)
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

ExpressionUnit Parser::findOperator(std::string &editedEquation)
{
    ExpressionUnit expressionUnit;
    expressionUnit.operation = editedEquation.at(0);
    expressionUnit.isValid = validateOperator(expressionUnit.operation);
    editedEquation_ = editedEquation.erase(0, 1);
    
    return expressionUnit;
}

bool Parser::validateOperator(const char &operation)
{
    bool isValid = false;

    for (size_t i = 0; CalculatorMessages::OPERATIONS[i] != '\0'; i++)
    {
        if (operation == CalculatorMessages::OPERATIONS[i])
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

ExpressionUnit Parser::findNumber(std::string &editedEquation)
{
    std::string numberString = CalculatorMessages::EMPTY_STRING;
    ExpressionUnit expressionUnit;

    for (auto currentChar : editedEquation)
    {
        if (currentChar == CalculatorMessages::OPERATIONS[1] && numberString.length() == 0)
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

    expressionUnit.isValid = validateFloat(numberString);
    if (expressionUnit.isValid)
    {
        expressionUnit.number = std::stof(numberString);
    }

    editedEquation_ = editedEquation_.erase(0, numberString.length());

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

} //namespace calculator
