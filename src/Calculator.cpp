
////////////////////////////////////////////////////////////////////////////
/**
 *  @file   Calculator.cpp
 *  @date   Fri April 16 2021
 *  @brief  Funtions that support main.cpp
 */
////////////////////////////////////////////////////////////////////////////

#include <algorithm>

#include "Calculator.h"
namespace calculator
{
    Calculator::Calculator() = default;

    Calculator::Calculator(int leftTerm, int rightTerm, Operation operation)
                        : leftTerm_(leftTerm), rightTerm_(rightTerm), operation_(operation)
    {
        calculateResult();
    }

    Calculator::Calculator(const std::string &mathExpression) 
    {
        std::stringstream expStream(mathExpression);
        int leftTerm, rightTerm;
        char operation;

        expStream >> leftTerm >> operation >> rightTerm;
        if(expStream)
        {
            leftTerm_ = leftTerm;
            rightTerm_ = rightTerm;
            if (std::find(validOperations_.begin(), validOperations_.end(), operation) != validOperations_.end())
            {
                operation_ = static_cast<Operation>(operation);
            }
            else
            {
                hasError_ = true;
                errorMessage_ += CalculatorStrings::ERROR_MESSAGE_INVALID_INPUT;
            }
        }
        else
        {
            hasError_ = true;
            errorMessage_ += CalculatorStrings::ERROR_MESSAGE_INVALID_INPUT;
        }

        calculateResult();
        // leaving this here just so you can see my previous attempt,
        // The lambda wasn't working how I wanted

        // //make this leftTerm private function instead?
        // auto trySetInt = [token](int &out)
        // {   
        //     std::string::size_type sz; 
        //     try
        //     {
        //         std::stoi(token, &sz);
        //     }
        //     catch(const std::invalid_argument &e)
        //     {
        //         return false;
        //     }
        //     if(token.length() != sz)
        //         return false;
        //     return true;
        // };

        // if (!trySetInt(leftTerm_)) 
        // {
        //     hasError_ = true;
        // }

        // expStream >> token;

        // if (token.length() == 1 &&
        //     std::find(validOperations_.begin(), validOperations_.end(), token[0]) != validOperations_.end())
        //     {
        //         //is casting here safe? Or would something like leftTerm switch statement be better?
        //         operation_ = (Operation)token[0];
        //     }
        // else
        // {
        //     hasError_ = true;
        // }

        // expStream >> token;

        // if(!trySetInt(rightTerm_)) 
        // {
        //     hasError_ = true;
        // }
    }

    Calculator::~Calculator() = default;

    int Calculator::getResult()
    {
        calculateResult();
        return result_;
    }

    void Calculator::calculateResult() 
    {
        switch (operation_)
        {
            case Operation::SUBTRACT:
            {
                result_ = subtract(leftTerm_, rightTerm_);
                break;
            }
            case Operation::MULTIPLY:
            {
                result_ = multiply(leftTerm_, rightTerm_);
                break;
            }
            case Operation::DIVIDE:
            {
                result_ = divide(leftTerm_, rightTerm_);
                break;
            }
            case Operation::ADD:
            {
                //Fallthrough
            }
            default:
            {
                result_ = add(leftTerm_, rightTerm_);
                break;
            }
        }
    }


    int Calculator::add(int leftTerm, int rightTerm)
    {
        return leftTerm + rightTerm;
    }

    int Calculator::subtract(int leftTerm, int rightTerm)
    {
        return add(leftTerm, -rightTerm);
    }

    int Calculator::divide(int leftTerm, int rightTerm)
    {
        if (rightTerm == 0)
        {
            hasError_ = true;
            errorMessage_ += CalculatorStrings::ERROR_MESSAGE_DIVIDE_BY_ZERO;
            return 0;
        }
        return leftTerm / rightTerm;
    }

    int Calculator::multiply(int leftTerm, int rightTerm)
    {
        return leftTerm * rightTerm;
    }

    std::string to_string(const Calculator &calculator)
    {
        return calculator.hasError_ ? CalculatorStrings::ERROR_MESSAGE + calculator.errorMessage_ : 
            std::to_string(calculator.leftTerm_) + CalculatorStrings::SPACE + 
            (char)calculator.operation_ + CalculatorStrings::SPACE + 
            std::to_string(calculator.rightTerm_) + CalculatorStrings::EQUAL + 
            std::to_string(calculator.result_);
    }

    std::ostream& operator<<(std::ostream& os, const Calculator &calculator) 
    {
        os << to_string(calculator);
        return os;
    }
}