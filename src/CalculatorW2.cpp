
////////////////////////////////////////////////////////////////////////////
/**
 *  @file   CalculatorW2.cpp
 *  @date   Fri April 16 2021
 *  @brief  Funtions that support main.cpp
 */
////////////////////////////////////////////////////////////////////////////

#include <algorithm>

#include "CalculatorW2.h"
namespace calculator
{
    CalculatorW2::CalculatorW2() = default;

    CalculatorW2::CalculatorW2(int leftTerm, int rightTerm, Operation operation)
                        : leftTerm_(leftTerm), rightTerm_(rightTerm), operation_(operation)
    {
        calculateResult();
    }

    CalculatorW2::CalculatorW2(const std::string &mathExpression) 
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

    CalculatorW2::~CalculatorW2() = default;

    int CalculatorW2::getResult()
    {
        calculateResult();
        return result_;
    }

    void CalculatorW2::calculateResult() 
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


    int CalculatorW2::add(int leftTerm, int rightTerm)
    {
        return leftTerm + rightTerm;
    }

    int CalculatorW2::subtract(int leftTerm, int rightTerm)
    {
        return add(leftTerm, -rightTerm);
    }

    int CalculatorW2::divide(int leftTerm, int rightTerm)
    {
        if (rightTerm == 0)
        {
            hasError_ = true;
            errorMessage_ += CalculatorStrings::ERROR_MESSAGE_DIVIDE_BY_ZERO;
            return 0;
        }
        return leftTerm / rightTerm;
    }

    int CalculatorW2::multiply(int leftTerm, int rightTerm)
    {
        return leftTerm * rightTerm;
    }

    std::string to_string(const CalculatorW2 &calculator)
    {
        return calculator.hasError_ ? CalculatorStrings::ERROR_MESSAGE + calculator.errorMessage_ : 
            std::to_string(calculator.leftTerm_) + CalculatorStrings::SPACE + 
            (char)calculator.operation_ + CalculatorStrings::SPACE + 
            std::to_string(calculator.rightTerm_) + CalculatorStrings::EQUAL + 
            std::to_string(calculator.result_);
    }

    std::ostream& operator<<(std::ostream& os, const CalculatorW2 &calculator) 
    {
        os << to_string(calculator);
        return os;
    }
}