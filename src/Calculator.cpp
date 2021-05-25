
////////////////////////////////////////////////////////////////////////////
/**
 *  @file   Calculator.cpp
 *  @date   Fri April 16 2021
 *  @brief  Funtions that support main.cpp
 */
////////////////////////////////////////////////////////////////////////////

#include <algorithm>

#include "Calculator.h"

// Add Function definitions here.
Calculator::Calculator() {}

Calculator::Calculator(int a, int b, Operation operation)
                      : a_(a), b_(b), operation_(operation)
{
    calculateResult();
}

Calculator::Calculator(const std::string &mathExpression) 
{
    std::stringstream expStream(mathExpression);
    int a, b;
    char operation;

    expStream >> a >> operation >> b;
    if(expStream)
    {
        a_ = a;
        b_ = b;
        if (std::find(validOperations_.begin(), validOperations_.end(), operation) != validOperations_.end())
        {
            //is casting here safe? Or would something like a switch statement be better?
            //we would have to update this code every time we added an operation if we did
            operation_ = (Operation)operation;
        }
        else
        {
            hasError_ = true;
            errorMessage_ += " invalid input ";
        }
    }
    else
    {
        hasError_ = true;
        errorMessage_ += " invalid input ";
    }

    calculateResult();
    // leaving this here just so you can see my previous attempt,
    // The lambda wasn't working how I wanted

    // //make this a private function instead?
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

    // if (!trySetInt(a_)) 
    // {
    //     hasError_ = true;
    // }

    // expStream >> token;

    // if (token.length() == 1 &&
    //     std::find(validOperations_.begin(), validOperations_.end(), token[0]) != validOperations_.end())
    //     {
    //         //is casting here safe? Or would something like a switch statement be better?
    //         operation_ = (Operation)token[0];
    //     }
    // else
    // {
    //     hasError_ = true;
    // }

    // expStream >> token;

    // if(!trySetInt(b_)) 
    // {
    //     hasError_ = true;
    // }
}

Calculator::~Calculator() {}

int Calculator::getResult()
{
    return result_;
}

void Calculator::calculateResult() 
{
    switch (operation_)
    {
        case Operation::SUBTRACT:
            result_ = subtract(a_, b_);
            break;
        case Operation::MULTIPLY:
            result_ = multiply(a_, b_);
            break;
        case Operation::DIVIDE:
            result_ = divide(a_, b_);
            break;
        case Operation::ADD:
            //fallthrough
        default:
            result_ = add(a_, b_);
            break;
    }
}


int Calculator::add(int a, int b)
 {
     return a + b;
 }

int Calculator::subtract(int a, int b)
{
    return add(a, -b);
}

int Calculator::divide(int a, int b)
{
    if (b == 0)
    {
        hasError_ = true;
        errorMessage_ += " divide by zero ";
        return -1;
    }
    return a / b;
}

int Calculator::multiply(int a, int b)
{
    return a * b;
}

std::string to_string(const Calculator &calculator)
{
    return calculator.hasError_ ? "Error: " + calculator.errorMessage_ : 
           std::to_string(calculator.a_) + " " + 
           (char)calculator.operation_ + " " + 
           std::to_string(calculator.b_) + " = " + 
           std::to_string(calculator.result_);
}

std::ostream& operator<<(std::ostream& os, const Calculator &calculator) 
{
    os << to_string(calculator);
    return os;
}