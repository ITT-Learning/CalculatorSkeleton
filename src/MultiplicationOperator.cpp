/**
 * @file MultiplicationOperator.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "MultiplicationOperator.h"
#include "OperatorFactory.h"

namespace Calculator
{
    bool MultiplicationOperator::REGISTERED = OperatorFactory::RegisterOperator(new MultiplicationOperator);

    MultiplicationOperator::MultiplicationOperator() : 
        IBinaryOperator(OpSymbol("*", OPORDER::FOUR, true)) {}

    MultiplicationOperator::~MultiplicationOperator() {}

    double MultiplicationOperator::calculate(double left, double right)
    { 
        return left * right; 
    }

    const std::string MultiplicationOperator::help()
    {
        return HELP_MULTIPLICATION_OPERATOR;
    }
}