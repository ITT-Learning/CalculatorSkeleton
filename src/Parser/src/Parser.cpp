////////////////////////////////////////////////////////////////////////////////
/**
* @file Parser.cpp
* @brief Function definitions for Parser.h
*/
////////////////////////////////////////////////////////////////////////////////

#include "Parser.h"

namespace calculator {

// ***************************************************************************** /
// ***************** Parser public methods ************************************* /
// ***************************************************************************** /

std::pair <std::shared_ptr<std::vector<ExpressionUnit>>,bool> Parser::createVector(const std::string &fullEquation)
{ 
    editedEquation_ = fullEquation;
    std::shared_ptr<std::vector<ExpressionUnit>> expressionUnits;
    expressionUnits = std::make_shared<std::vector<ExpressionUnit>>();
    ExpressionUnit currentUnit;
    bool isCheckingNumber = true;
    bool isValidExpression = true;

    std::this_thread::sleep_for(std::chrono::milliseconds(300)); //sleeping to show off thread in use

    while (editedEquation_.length() > 0)
    {
        if (editedEquation_.at(0) == '(' || editedEquation_.at(0) == ')')
        {
            if (editedEquation_.at(0) == '(')
            {
                isCheckingNumber = false;
            }
            if (editedEquation_.at(0) == ')')
            {
                isCheckingNumber = true;
            }
            currentUnit.operation = editedEquation_.at(0);
            currentUnit.valid = true;
            editedEquation_ = editedEquation_.erase(0, 1);
        }
        else
        {
            isCheckingNumber ? currentUnit = findNumber(editedEquation_) : currentUnit = findOperator(editedEquation_);
        }
        if(currentUnit.valid)
        {
            isCheckingNumber = !isCheckingNumber;
            expressionUnits->push_back(currentUnit);
        }
        else
        {
            isValidExpression = false;
            break;
        }
    }

    if(isValidExpression && expressionUnits->size() < ExpressionUnit::PARSED_EXPRESSION_LENGTH) // ensuring an expressionUnit vector has at least ExpressionUnit::PARSED_EXPRESSION_LENGTH units
    {
        std::cout << CalculatorStrings::ERROR_MESSAGE_INVALID_INPUT_LENGTH << std::endl;
        isValidExpression = false;
    }
    if(isValidExpression)
    {
        isValidExpression = validateParenthesis(expressionUnits);
    }

    std::pair < std::shared_ptr<std::vector<ExpressionUnit>>,bool> completedVector (expressionUnits, isValidExpression);
    
    return completedVector;
}

Expression Parser::breakDownEquation(const std::shared_ptr<std::vector<ExpressionUnit>> &expressionUnits)
{
    Expression parsedExpression;
    char       importantOperator;
    int        parenthesisIndex;
    char       lastParenthesis = '(';
    size_t     startingPoint = 0;
    size_t     endingPoint = expressionUnits->size();
    
    std::this_thread::sleep_for(std::chrono::milliseconds(800)); //sleeping to show off thread in use

    for (size_t i = 0; i < expressionUnits->size(); i++) //find parenthesis that open then close
    {
        if (expressionUnits->at(i).operation == '(')
        {
            startingPoint = i;
        }
        if (expressionUnits->at(i).operation == ')' && lastParenthesis == '(')
        {
            endingPoint = i;
            expressionUnits->erase(expressionUnits->begin() + startingPoint); //erase parenthesis
            expressionUnits->erase(expressionUnits->begin() + (endingPoint - 1));
            endingPoint = endingPoint - ExpressionUnit::LENGTH_OVER_OPERATOR;
            break;
        }           
        if (expressionUnits->at(i).operation == '(' || expressionUnits->at(i).operation == ')')
        {
            lastParenthesis = expressionUnits->at(i).operation;
        }
    }

    if ((startingPoint + ExpressionUnit::LENGTH_OVER_OPERATOR) <= endingPoint) // check to ensure user didn't enter something like "(1+)"
    {
        for (size_t i = startingPoint; i < endingPoint; i++) //find operator in order
        {
            if (expressionUnits->at(i).valid)
            {
                parsedExpression.validExpression = true;
                if (expressionUnits->at(i).operation == '/' || 
                    expressionUnits->at(i).operation == '%' || 
                    expressionUnits->at(i).operation == 'x' || 
                    expressionUnits->at(i).operation == '*')
                {
                    importantOperator = expressionUnits->at(i).operation;
                    parsedExpression.placementIndex = i - 1;
                    break;
                }
                if (expressionUnits->at(i).operation == '-' || expressionUnits->at(i).operation == '+')
                {
                    if(importantOperator != '-' && importantOperator != '+')
                    {
                        importantOperator = expressionUnits->at(i).operation;
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
        expressionUnits->erase(expressionUnits->begin() + startingPoint, expressionUnits->begin() + endingPoint);
    }
    if (parsedExpression.validExpression)
    {
        parsedExpression.operation = importantOperator; //set up expression Object
        parsedExpression.firstNumber = expressionUnits->at(parsedExpression.placementIndex).number; // start at the first unit of expression
        parsedExpression.secondNumber = expressionUnits->at(parsedExpression.placementIndex + ExpressionUnit::LENGTH_OVER_OPERATOR).number; // find the next number unit by adding ExpressionUnit::LENGTH_OVER_OPERATOR (skipping over the operator)
        expressionUnits->erase(
        expressionUnits->begin() + parsedExpression.placementIndex, //erase starting at the first number
        expressionUnits->begin() + parsedExpression.placementIndex + ExpressionUnit::PARSED_EXPRESSION_LENGTH); //delete ExpressionUnit::PARSED_EXPRESSION_LENGTH units (the length of a parsed expression)
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


bool Parser::validateParenthesis(std::shared_ptr<std::vector<ExpressionUnit>> &expressionUnits)
{
    int openParenthesisCount = 0;
    int closeParenthesisCount = 0;
    
    for (size_t i = 0; i < expressionUnits->size(); i++) //find parenthesis
    {
        if (expressionUnits->at(i).valid)
        {
            if (expressionUnits->at(i).operation == '(')
            {
                openParenthesisCount ++;
            }
            if (expressionUnits->at(i).operation == ')')
            {
                closeParenthesisCount ++;
            }
        }
    }

    if (openParenthesisCount != closeParenthesisCount)
    {
        std::cout << CalculatorStrings::ERROR_MESSAGE_UNKNOWN_OPERATOR << std::endl;
    }
    return openParenthesisCount == closeParenthesisCount;
}

ExpressionUnit Parser::findOperator(std::string &editedEquation_)
{
    ExpressionUnit expressionUnit;
    expressionUnit.operation = editedEquation_.at(0);
    expressionUnit.valid = validateOperator(expressionUnit.operation);
    editedEquation_ = editedEquation_.erase(0, 1);
    
    return expressionUnit;
}

bool Parser::validateOperator(const char &expressionUnit)
{
    bool isValid = false;

    for (auto currentOperator : operations_)
    {
        if (expressionUnit == currentOperator)
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

bool Parser::validateFloat(const std::string &floatString)
{
    bool isValid =false;
    static const std::regex floatRegex{CalculatorStrings::FLOAT_REGEX};

    if (std::regex_match(floatString, floatRegex))
    {
        isValid = true;
    }
    else
    {
        std::cout << CalculatorStrings::ERROR_MESSAGE_INVALID_INPUT << std::endl;
    }

    return isValid;
}

ExpressionUnit Parser::findNumber(std::string &editedEquation_)
{
    std::string numberString = "";
    ExpressionUnit expressionUnit;

    for (auto currentChar : editedEquation_)
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
    editedEquation_ = editedEquation_.erase(0, numberString.length());

    return expressionUnit;
    
}

    std::string Parser::removeSpaces(const std::string &userInput)
{
    std::string fullEquation;
        for (auto currentChar : userInput)
        {
            if(currentChar == CalculatorStrings::EMPTY_SPACE)
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

} // namespace calculator
