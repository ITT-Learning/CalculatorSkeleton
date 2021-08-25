/**
 * @file AdditionOperator.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "AdditionOperator.h"
#include "OperatorFactory.h"

namespace Calculator
{
    bool AdditionOperator::REGISTERED = OperatorFactory::RegisterOperator(new AdditionOperator);

    AdditionOperator::AdditionOperator() : 
        IBinaryOperator(OpSymbol("+", OPORDER::FIVE, true)) {}

    AdditionOperator::~AdditionOperator() {}

    double AdditionOperator::calculate(double left, double right)
    { 
        return left + right; 
    } 

    const std::string AdditionOperator::help()
    {
        return HELP_ADDITION_OPERATOR;
    }
}