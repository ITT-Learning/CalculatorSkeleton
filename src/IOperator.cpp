/**
 * @file IOperator.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-18
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "IOperator.h"

namespace Calculator
{
    IOperator::IOperator(const OpSymbol opsymbol) :
        opsymbol_(opsymbol) {}

    IOperator::~IOperator() {}

    OpSymbol IOperator::GetOpSymbol()
    {
        return opsymbol_;
    }
}