/**
 * @file SquareRootOperator.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include  <tgmath.h>

#include "SquareRootOperator.h"

namespace Calculator
{
    SquareRootOperator::SquareRootOperator() :
        IUnaryOperator(OpSymbol("sqrt", OPORDER::THREE)) {}

    SquareRootOperator::~SquareRootOperator() {}

    double SquareRootOperator::calculate(double input) 
    { 
        return  sqrt(input);
    }
}