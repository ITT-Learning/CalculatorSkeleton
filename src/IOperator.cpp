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
    IOperator::IOperator(OPORDER oporder, std::string opregex) :
        oporder_(oporder), opregex_(opregex) {}

    IOperator::~IOperator() {}

    OPORDER IOperator::OpOrder()
    {
        return oporder_;
    }

    std::string IOperator::OpRegex()
    {
        return opregex_;
    }
}