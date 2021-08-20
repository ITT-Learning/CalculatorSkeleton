/**
 * @file AbsoluteOperator.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <cmath>

#include "AbsoluteOperator.h"
#include "OperatorFactory.h"

namespace Calculator
{

    AbsoluteOperator::AbsoluteOperator() :
        IUnaryOperator(OpSymbol("abs", OPORDER::THREE)) {}

    AbsoluteOperator::~AbsoluteOperator() {}

    double AbsoluteOperator::calculate(double input) 
    {
        return  std::fabs(input);
    }
}