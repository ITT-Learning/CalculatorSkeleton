////////////////////////////////////////////////////////////////////////////////
/**
* @file Parser.cpp
* @brief Function definitions for Parser
*/
////////////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include <iostream>
#include <regex>
#include <string>
#include <utility>
#include <vector>

#include "CalculatorMessages.h"
#include "Parser.h"


namespace calculator
{
    std::pair <std::vector<ExpressionUnit>,bool> Parser::createVector(const std::string &fullEquation)
    { 
        editedEquation = fullEquation;
        std::vector<ExpressionUnit> equationVector;
        ExpressionUnit currentUnit;
        bool checkingNumber = true;
        bool validVector = true;

        while (editedEquation.length() > 0)
        {
            checkingNumber ? currentUnit = findNumber(editedEquation) : currentUnit = findOperator(editedEquation);

            if(currentUnit.valid)
            {
                equationVector.push_back(currentUnit);
                checkingNumber = !checkingNumber;
            }
            else
            {
                validVector=false;
                break;
            }
        }

        if(validVector && equationVector.size() < 3) // input length check
        {
            std::cout << CalculatorMessages::ERROR_MESSAGE << CalculatorMessages::ERROR_MESSAGE_INVALID_INPUT_LENGTH << std::endl;
            validVector = false;
        }

        std::pair <std::vector<ExpressionUnit>,bool> completedVector (equationVector, validVector);
        return completedVector;
    }

    Expression Parser::breakDownEquation(std::vector<ExpressionUnit> &equationVector)
    {
        Expression parsedExpression;
        char importantOperator;
    
        for (size_t i = 0; i < equationVector.size(); i++) //find operator in order
        {
            if (equationVector.at(i).valid)
            {
                parsedExpression.validExpression = true;
                if (equationVector.at(i).operation == '/' || equationVector.at(i).operation == '%' || equationVector.at(i).operation == 'x' || equationVector.at(i).operation == '*')
                {
                    importantOperator = equationVector.at(i).operation;
                    parsedExpression.placementIndex = i - 1;
                    break;
                }
                if (equationVector.at(i).operation == '-' || equationVector.at(i).operation == '+')
                {
                    if(importantOperator != '-' && importantOperator != '+')
                    {
                        importantOperator = equationVector.at(i).operation;
                        parsedExpression.placementIndex = i - 1;
                    }
                        continue;
                }
            }
            else
            {
                parsedExpression.validExpression = false;
                break;
            }
        }

        parsedExpression.operation = importantOperator; //set up expression Object
        parsedExpression.a = equationVector.at(parsedExpression.placementIndex).number;
        parsedExpression.b = equationVector.at(parsedExpression.placementIndex + 2).number;

        equationVector.erase(equationVector.begin() + parsedExpression.placementIndex, equationVector.begin() + parsedExpression.placementIndex + 3);

        return parsedExpression;
    }

    std::string Parser::getUserInput()
    {
        std::cout << CalculatorMessages::INTRODUCTION_MESSAGE << std::endl;
        std::cout << CalculatorMessages::INSTRUCTIONS_MESSAGE << std::endl;

        std::string userInput;

        getline(std::cin, userInput);

        if (userInput == "")
        {
            getline(std::cin, userInput);
        }
        originalEquation = userInput;
        return removeSpaces(userInput); 
    }

    //*************/
    // Parser private methods /
    ///

    ExpressionUnit Parser::findOperator(std::string &editedEquation)
    {
        ExpressionUnit expressionUnit;
        expressionUnit.operation = editedEquation.at(0);
        expressionUnit.valid = validateOperator(expressionUnit.operation);
        editedEquation = editedEquation.erase(0, 1);
        
        return expressionUnit;
    }

    bool Parser::validateOperator(const char &expressionUnit)
    {
        bool isValid = false;

        for (auto currentOperator : Operations)
        {
            if (expressionUnit == currentOperator)
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
        static const std::regex floatRegex{ R"([+-]?([0-9]+([.][0-9]*)?|[.][0-9]+))"};

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
        std::string numberString = "";
        ExpressionUnit expressionUnit;

        for (auto currentChar : editedEquation)
        {
            if (currentChar == '-' && numberString.length() == 0)
            {
                numberString += currentChar;
            }
            else if (currentChar == '.')
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

        expressionUnit.valid = validateFloat(numberString);
        if (expressionUnit.valid)
        {
            expressionUnit.number = std::stof(numberString);
        }
        editedEquation = editedEquation.erase(0, numberString.length());
    
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
                    fullEquation+=currentChar;
                }
            }
            return fullEquation;
    }
}
