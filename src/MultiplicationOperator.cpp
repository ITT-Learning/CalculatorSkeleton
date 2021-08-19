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

namespace Calculator
{
    MultiplicationOperator::MultiplicationOperator() : 
        IBinaryOperator(OpSymbol("*", OPORDER::FOUR, true)) {}

    MultiplicationOperator::~MultiplicationOperator() {}

    double MultiplicationOperator::calculate(double left, double right)
    { 
        return left * right; 
    } 
}