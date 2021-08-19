/**
 * @file DivisionOperator.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "DivisionOperator.h"

namespace Calculator
{
    DivisionOperator::DivisionOperator() : 
        IBinaryOperator(OpSymbol("/", OPORDER::FOUR)) {}

    DivisionOperator::~DivisionOperator() {}

    double DivisionOperator::calculate(double left, double right)
    { 
        return left / right; 
    } 
}