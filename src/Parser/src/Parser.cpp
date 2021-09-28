////////////////////////////////////////////////////////////////////////////////
/**
* @file Parser.cpp
* @brief Function definitions and class for Parser
*/
////////////////////////////////////////////////////////////////////////////////

#include "Parser.h"
#include "CalculatorMessages.h"
#include <iostream>
#include <string>
#include <regex>


namespace calculator
{
    Expression Parser::parseExpression(std::string expression)
    {
        Expression parsedExpression;
        std::string edittedStr = findNumber(expression);

        parsedExpression.valid = validateFloat(edittedStr);

        if (parsedExpression.valid)
        {
            parsedExpression.a = std::stof(edittedStr);
            parsedExpression.operation = expression.substr(edittedStr.length(), 1)[0];
            parsedExpression.valid = validateOperator(parsedExpression.operation);
        }
        if (parsedExpression.valid)
        {
            edittedStr = expression.substr(edittedStr.length() + 1);
            parsedExpression.valid = validateFloat(edittedStr);
        }
        if (parsedExpression.valid)
        {
            parsedExpression.b = std::stof(findNumber(edittedStr));
        } 

        return parsedExpression;
    }

    std::string Parser::getUserInput()
    {
        std::cout << CalculatorMessages::INTRODUCTION_MESSAGE << std::endl;
        std::cout << CalculatorMessages::INSTRUCTIONS_MESSAGE << std::endl;

        std::string input;

        getline(std::cin, input);

        if (input == "")
        {
            getline(std::cin, input);
        }
        
        return removeSpaces(input); 
    }

    //*************/
    // Parser private methods /
    ///

    std::string Parser::removeSpaces(std::string &input)
    {
        std::string fullEquation;
            for (auto currentChar : input)
            {
                if(currentChar == CalculatorMessages::EMPTY_SPACE) // always skip a space
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
    
    bool Parser::validateOperator(const char &expression)
    {
        bool isValid = false;

        for (auto currentOperator : Operations)
        {
            if (expression == currentOperator)
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

    bool Parser::validateFloat(const std::string &expression)
    {
        bool isValid = true;
        static const std::regex floatRegex{ R"([+-]?([0-9]+([.][0-9]*)?|[.][0-9]+))"};

        if (std::regex_match(expression, floatRegex))
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

    std::string Parser::findNumber(const std::string &expression)
    {
        std::string numberString = "";

        for (auto currentChar : expression)
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

        return numberString;
    }
}