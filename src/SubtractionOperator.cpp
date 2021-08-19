/**
 * @file SubtractionOperator.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "SubtractionOperator.h"

namespace Calculator
{
    SubtractionOperator::SubtractionOperator() : 
        IBinaryOperator(OpSymbol("-", OPORDER::FIVE)) {}

    SubtractionOperator::~SubtractionOperator() {}

    double SubtractionOperator::calculate(double left, double right)
    { 
        return left - right; 
    } 
}