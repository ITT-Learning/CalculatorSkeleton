////////////////////////////////////////////////////////////////////////////////
/**
* @file Parser.cpp
* @brief Function definitions for Parser
*/
////////////////////////////////////////////////////////////////////////////////

#include <regex>

#include "../inc/Parser.h"

namespace calculator
{
    Expression Parser::parseFullEquation(const std::string &fullEquation)
    {
        Expression parsedExpression;
        std::string expressionPiece = findNumber(fullEquation);

        parsedExpression.valid = validateFloat(expressionPiece);

        if (parsedExpression.valid)
        {
            parsedExpression.a = std::stof(expressionPiece);
            parsedExpression.operation = fullEquation.substr(expressionPiece.length(), 1)[0];
            parsedExpression.valid = validateOperator(parsedExpression.operation);
        }
        if (parsedExpression.valid)
        {
            expressionPiece = fullEquation.substr(expressionPiece.length() + 1);
            parsedExpression.valid = validateFloat(expressionPiece);
        }
        if (parsedExpression.valid)
        {
            parsedExpression.b = std::stof(findNumber(expressionPiece));
        } 

        return parsedExpression;
    }

    std::string Parser::getUserInput()
    {
        std::cout << CalculatorStrings::WELCOME_MESSAGE << std::endl;
        std::cout << CalculatorStrings::ENTER_EQUATION << std::endl;

        std::string userInput;

        getline(std::cin, userInput);

        if (userInput == "")
        {
            getline(std::cin, userInput);
        }
        
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
                if(currentChar == CalculatorStrings::EMPTY_SPACE) // always skip a space
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
    
    bool Parser::validateOperator(const char &parsedOperation)
    {
        bool isValid = false;

        for (auto currentOperator : Operations)
        {
            if (parsedOperation == currentOperator)
            {
                isValid = true;
            }
        }
        if (!isValid)
        {
            std::cout << CalculatorStrings::ERROR_MESSAGE_UNKNOWN_OPERATOR << std::endl;
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
            std::cout << CalculatorStrings::ERROR_MESSAGE_INVALID_INPUT << std::endl;
        }

        return isValid;
    }

    std::string Parser::findNumber(const std::string &expressionPiece)
    {
        std::string numberString = "";

        for (auto currentChar : expressionPiece)
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
