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
    std::shared_ptr<std::vector<ExpressionUnit>> equationVector;
    equationVector = std::make_shared<std::vector<ExpressionUnit>>();
    ExpressionUnit currentUnit;
    bool checkingNumber = true;
    bool validVector = true;

    std::this_thread::sleep_for(std::chrono::milliseconds(300)); //sleeping to show off thread in use

    while (editedEquation_.length() > 0)
    {
        if (editedEquation_.at(0) == '(' || editedEquation_.at(0) == ')')
        {
            if (editedEquation_.at(0) == '(')
            {
                checkingNumber = false;
            }
            if (editedEquation_.at(0) == ')')
            {
                checkingNumber = true;
            }
            currentUnit.operation = editedEquation_.at(0);
            currentUnit.valid = true;
            editedEquation_ = editedEquation_.erase(0, 1);
        }
        else
        {
            checkingNumber ? currentUnit = findNumber(editedEquation_) : currentUnit = findOperator(editedEquation_);
        }
        if(currentUnit.valid)
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
        std::cout << CalculatorStrings::ERROR_MESSAGE_INVALID_INPUT_LENGTH << std::endl;
        validVector = false;
    }
    if(validVector)
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
    int        parenthesisIndex;
    char       lastParenthesis = '(';
    size_t     startingPoint = 0;
    size_t     endingPoint = equationVector->size();
    
    std::this_thread::sleep_for(std::chrono::milliseconds(800)); //sleeping to show off thread in use

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

    if ((startingPoint + 2) <= endingPoint) // check to ensure user didn't enter something like "(1+)"
    {
        for (size_t i = startingPoint; i < endingPoint; i++) //find operator in order
        {
            if (equationVector->at(i).valid)
            {
                parsedExpression.validExpression = true;
                if (equationVector->at(i).operation == '/' || 
                    equationVector->at(i).operation == '%' || 
                    equationVector->at(i).operation == 'x' || 
                    equationVector->at(i).operation == '*')
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
        parsedExpression.firstNumber = equationVector->at(parsedExpression.placementIndex).number; // start at the first unit of expression
        parsedExpression.secondNumber = equationVector->at(parsedExpression.placementIndex + 2).number; // find the next number unit by adding 2 (skipping over the operator)
        equationVector->erase(
        equationVector->begin() + parsedExpression.placementIndex, //erase starting at the first number
        equationVector->begin() + parsedExpression.placementIndex + 3); //delete 3 units (the length of a parsed expression)
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
