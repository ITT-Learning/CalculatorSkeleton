////////////////////////////////////////////////////////////////////////////////
/**
* @file Parser.cpp
* @brief Function definitions and class for calculator
*/
////////////////////////////////////////////////////////////////////////////////

#include "Parser.h"
#include "CalculatorMessages.h"

namespace calculator
{
    //static?
    bool Parser::validateExpression(const std::string &expression)
    {
        enum class CalculateStates 
        {
            FindingNumber1,
            OperatorFound,
            FindingNumber2
        };

        CalculateStates CurrentState = CalculateStates::FindingNumber1;
        char operation;
        fullEquation = "";
        std::string number2Str;
        bool isValid = true;
        
        if (expression.length() > 0)
        {
            //for (size_t i = 0; i < expression.length(); i++))
            //for (std::iterator it = expression.begin(); it < expression.end(); it++)
            for (auto currentChar : expression)
            {
                if(currentChar == CalculatorMessages::EMPTY_SPACE)
                {
                    continue;
                }
                switch (CurrentState)
                {
                    case CalculateStates::FindingNumber1:
                    {
                        if(std::isdigit(currentChar)) //if expression is a number
                        {
                            fullEquation += currentChar;
                        }
                        else if(!std::isdigit(fullEquation.back())) // if there are no digits yet
                        {
                            if(currentChar == '-') // if first expression is a -
                            {
                                if (fullEquation.length() == 0) // ensuring it's first
                                {
                                    fullEquation += currentChar;
                                }
                                else // two minuses
                                {
                                    isValid = false;
                                }
                            }
                            else
                            {
                                isValid = false; 
                            }
                        }
                        else //if expression not a number
                        {
                            if(std::isdigit(fullEquation.back())) // if equation has a number
                            {
                                if(currentChar == '.')
                                {
                                    fullEquation += currentChar;
                                    continue;
                                }
                                else
                                {
                                    CurrentState = CalculateStates::OperatorFound;
                                    i--;
                                }
                            }
                        }
                            break;
                    }
                    case CalculateStates::OperatorFound:
                    {
                        operation = currentChar;

                        if(operation == '+' || operation == '-' || operation == '*' || operation == '/')
                        {
                            fullEquation += CalculatorMessages::EMPTY_SPACE;
                            fullEquation += operation;
                            fullEquation += CalculatorMessages::EMPTY_SPACE;
                            CurrentState = CalculateStates::FindingNumber2;
                        }
                        else
                        {
                            isValid = false;
                        }
                        break;
                    }
                    case CalculateStates::FindingNumber2:
                    {
                        if(std::isdigit(currentChar)) //if expression is a number
                        {
                            fullEquation += currentChar;
                            number2Str += currentChar;
                        }
                        else if(!std::isdigit(fullEquation.back())) // if end of full equation is not a number
                        {
                            if(currentChar == '-') // if first expression is a -
                            {
                                if (number2Str.length() == 0 ) // ensuring it's first in second number
                                    {
                                        fullEquation += currentChar;
                                    }
                                    else // two minuses?
                                    {
                                        isValid = false;
                                    }
                            }
                            else
                            {
                                isValid = false;
                            }
                        }
                        else //if expression not a number
                        {
                            if(currentChar == '.')
                            {
                                fullEquation += currentChar;
                                continue;
                            }
                            else{
                            isValid = false;  
                            }
                        }
                        break;
                    }
                    default:
                    break;
                }
            }
        } 
        else
            {
                isValid = false;
            }
        return isValid;
    }

}//namespace calculator
