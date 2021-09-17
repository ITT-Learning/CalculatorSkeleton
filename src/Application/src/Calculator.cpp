////////////////////////////////////////////////////////////////////////////////
/**
* @file Calculator.cpp
* @brief Function definitions and class for calculator
*/
////////////////////////////////////////////////////////////////////////////////

#include "Calculator.h"
#include <stdlib.h>
#include <iostream>
#include <typeinfo>
#include "CalculatorMessages.h"
#include <sstream>
#include<math.h>

namespace calculator
{

//*************/
// Calculator public methods /
///
   
    void Calculator::runCalculator()
    {
        if (validateInput(getUserInput()))
        {
            char operation;
            float number1;
            float number2;

            std::stringstream ss {fullEquation};
            ss >> number1 >> operation >> number2;
        
            std::cout << fullEquation << CalculatorMessages::EQUALS << calculate(operation, number1, number2) << std::endl;
        }
        else
        {
            std::cout << CalculatorMessages::ERROR_MESSAGE << CalculatorMessages::ERROR_MESSAGE_INVALID_INPUT << std::endl;
        }
    }

    bool Calculator::validateInput(const std::string &input)
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
        
        if (input.length()>0)
        {
            for (size_t i = 0; i < input.length(); i++)
            {
                if(input.at(i) == CalculatorMessages::EMPTY_SPACE)
                {
                    continue;
                }
                switch (CurrentState)
                {
                    case CalculateStates::FindingNumber1:
                    {
                        if(std::isdigit(input.at(i))) //if input is a number
                        {
                            fullEquation += input.at(i);
                        }
                        else if(!std::isdigit(fullEquation.back())) // if there are no digits yet
                        {
                            if(input.at(i) == '-') // if first input is a -
                            {
                                if (fullEquation.length() == 0) // ensuring it's first
                                {
                                    fullEquation += input.at(i);
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
                        else //if input not a number
                        {
                            if(std::isdigit(fullEquation.back())) // if equation has a number
                            {
                                if(input.at(i) == '.')
                                {
                                    fullEquation += input.at(i);
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
                        operation = input.at(i);

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
                        if(std::isdigit(input.at(i))) //if input is a number
                        {
                            fullEquation += input.at(i);
                            number2Str += input.at(i);
                        }
                        else if(!std::isdigit(fullEquation.back())) // if end of full equation is not a number
                        {
                            if(input.at(i) == '-') // if first input is a -
                            {
                                if (number2Str.length() == 0 ) // ensuring it's first in second number
                                    {
                                        fullEquation += input.at(i);
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
                        else //if input not a number
                        {
                            if(input.at(i) == '.')
                            {
                                fullEquation += input.at(i);
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

    float Calculator::calculate(char operation, float number1, float number2)
    {
        
        double answer;    
            switch (operation)
            {
            case '+':
            {
                answer = add(number1, number2);
                break;
            }
            case '-':
            {
                answer = subtract(number1, number2);
                break;
            }
            case 'x':
            {
                answer = multiply(number1, number2);
                break;
            }
            case '*':
            {
                answer = multiply(number1, number2);
                break;
            }
            case '/':
            {
                answer = divide(number1, number2);
                break;
            }
            case '%':
            {
                answer = divide(number1, number2);
                break;
            }
            default:
                std::cout << CalculatorMessages::ERROR_MESSAGE << CalculatorMessages::ERROR_INVALID_OPERATOR << std::endl;
            }
        return answer;
    }


//*************/
// Calculator private methods /
///
    std::string Calculator::getUserInput()
    {
        std::cout << CalculatorMessages::INTRODUCTION_MESSAGE << std::endl;
        std::cout << CalculatorMessages::INSTRUCTIONS_MESSAGE << std::endl;

        std::string input;

        getline(std::cin, input);

        if (input == "")
        {
            getline(std::cin, input);
        }
        else
        {
            return input;
        }
    }

    float Calculator::add(double number1, double number2)
    {
        return number1 + number2;
    }

    float Calculator::subtract(double number1, double number2)
    {
        return number1 - number2;
    }

    float Calculator::divide(double number1, double number2)
    {
        float ans = number1 / number2;
        if (isinf(ans)) //if you divided by zero
        {
            std::cout << CalculatorMessages::ERROR_MESSAGE << CalculatorMessages::ERROR_MESSAGE_DIVIDE_BY_ZERO << std::endl;
        }

        return ans;
    }

    float Calculator::multiply(double number1, double number2)
    {
        return number1 * number2;
    }
}//namespace calculator
