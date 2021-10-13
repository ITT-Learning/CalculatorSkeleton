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
#include <vector>

#include "CalculatorMessages.h"
#include "Parser.h"


namespace calculator
{
     std::vector<ExpressionUnit> Parser::createVector(const std::string &fullEquation)
    { 
        editedEquation = fullEquation;
        std::vector<ExpressionUnit> equationVector;
        while (editedEquation.length() > 0)
        {
            equationVector.push_back(findNumber(editedEquation));
            if(editedEquation.length() > 0)
            {
                equationVector.push_back(findOperator(editedEquation));
            }
        }

        return equationVector;
    }

    Expression Parser::parseFullEquation(std::vector<ExpressionUnit> &equationVector)
    {
        Expression parsedExpression;
        char importantOperator;

        for (size_t i = 0; i < equationVector.size(); i++) //find operator in order
        {
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

    bool Parser::validateFloat(const std::string &expressionPiece)
    {
        bool isValid = true;
        static const std::regex floatRegex{ R"([+-]?([0-9]+([.][0-9]*)?|[.][0-9]+))"};

        if (std::regex_match(expressionPiece, floatRegex))
        {
            isValid = true;
        }
        else
        {
            isValid = false;
            std::cout << CalculatorMessages::ERROR_MESSAGE << CalculatorMessages::ERROR_MESSAGE_INVALID_INPUT << std::endl;
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
        expressionUnit.number = std::stof(numberString);
        editedEquation = editedEquation.erase(0, numberString.length());
    
        return expressionUnit;
        
    }
}
