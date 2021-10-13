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


namespace calculator
{
    std::pair <std::shared_ptr<std::vector<ExpressionUnit>>,bool> Parser::createVector(const std::string &fullEquation)
    { 
        editedEquation = fullEquation;
        std::shared_ptr<std::vector<ExpressionUnit>> equationVector;
        equationVector = std::make_shared<std::vector<ExpressionUnit>>();
        ExpressionUnit currentUnit;
        bool checkingNumber = true;
        bool validVector = true;

        std::this_thread::sleep_for(std::chrono::milliseconds(300));

        while (editedEquation.length() > 0)
        {
            if (editedEquation.at(0) == '(' || editedEquation.at(0) == ')')
            {
                if (editedEquation.at(0) == '(')
                {
                    checkingNumber = false;
                }
                if (editedEquation.at(0) == ')')
                {
                    checkingNumber = true;
                }
                currentUnit.operation = editedEquation.at(0);
                currentUnit.valid = true;
                editedEquation = editedEquation.erase(0, 1);
            }
            else
            {
                checkingNumber ? currentUnit = findNumber(editedEquation) : currentUnit = findOperator(editedEquation);
            }
            if(currentUnit.valid)
            {
                checkingNumber = !checkingNumber;
                equationVector->push_back(currentUnit);
            }
            else
            {
                validVector=false;
                break;
            }
        }

        if(validVector && equationVector->size() < 3) // input length check
        {
            std::cout << CalculatorMessages::ERROR_MESSAGE << CalculatorMessages::ERROR_MESSAGE_INVALID_INPUT_LENGTH << std::endl;
            validVector = false;
        }

        validVector = validateParenthesis(equationVector);

        std::pair < std::shared_ptr<std::vector<ExpressionUnit>>,bool> completedVector (equationVector, validVector);
        return completedVector;
    }

    Expression Parser::breakDownEquation(const std::shared_ptr<std::vector<ExpressionUnit>> &equationVector)
    {
        Expression parsedExpression;
        char importantOperator;
        int parenthesisIndex;
        char lastParenthesis = '(';
        size_t startingPoint = 0;
        size_t endingPoint = equationVector->size();
        
        std::this_thread::sleep_for(std::chrono::milliseconds(800));

        for (size_t i = 0; i < equationVector->size(); i++) //find parenthesis that open then close
        {
            if (equationVector->at(i).operation == '(')
            {
                startingPoint = i;
            }
            if (equationVector->at(i).operation == ')' && lastParenthesis == '(')
            {
                endingPoint = i;
                equationVector->erase(equationVector->begin() + startingPoint); //erase parenthesis
                equationVector->erase(equationVector->begin() + (endingPoint - 1));
                endingPoint = endingPoint - 2;
                break;
            }           
            if (equationVector->at(i).operation == '(' || equationVector->at(i).operation == ')')
            {
                lastParenthesis = equationVector->at(i).operation;
            }
        }

        if ((startingPoint + 2) <= endingPoint) // if you enter something like "(1+)"
        {
            for (size_t i = startingPoint; i < endingPoint; i++) //find operator in order
            {
                if (equationVector->at(i).valid)
                {
                    parsedExpression.validExpression = true;
                    if (equationVector->at(i).operation == '/' || equationVector->at(i).operation == '%' || equationVector->at(i).operation == 'x' || equationVector->at(i).operation == '*')
                    {
                        importantOperator = equationVector->at(i).operation;
                        parsedExpression.placementIndex = i - 1;
                        break;
                    }
                    if (equationVector->at(i).operation == '-' || equationVector->at(i).operation == '+')
                    {
                        if(importantOperator != '-' && importantOperator != '+')
                        {
                            importantOperator = equationVector->at(i).operation;
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
        }
        else
        {
            parsedExpression.validExpression = false;
            equationVector->erase(equationVector->begin() + startingPoint, equationVector->begin() + endingPoint);
        }

        if (parsedExpression.validExpression)
        {
            parsedExpression.operation = importantOperator; //set up expression Object
            parsedExpression.a = equationVector->at(parsedExpression.placementIndex).number;
            parsedExpression.b = equationVector->at(parsedExpression.placementIndex + 2).number;
            equationVector->erase(equationVector->begin() + parsedExpression.placementIndex, equationVector->begin() + parsedExpression.placementIndex + 3);
        }

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

    std::string Parser::getOriginalEquation()
    {
        return originalEquation;
    }

    //*************/
    // Parser private methods /
    ///

    bool Parser::validateParenthesis(std::shared_ptr<std::vector<ExpressionUnit>> &equationVector)
    {
        int openParenthesisCount = 0;
        int closeParenthesisCount = 0;
        
        for (size_t i = 0; i < equationVector->size(); i++) //find parenthesis
        {
            if (equationVector->at(i).valid)
            {
                if (equationVector->at(i).operation == '(')
                {
                    openParenthesisCount ++;
                }
                if (equationVector->at(i).operation == ')')
                {
                    closeParenthesisCount ++;
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
