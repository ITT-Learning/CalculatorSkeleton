/**
 * @file OpSymbol.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "OpSymbol.h"

namespace Calculator
{
    OpSymbol::OpSymbol(std::string id, OPORDER order, bool escape) :
        id_(id), order_(order), escape_(escape) {}

    OpSymbol::~OpSymbol() {}

    std::string OpSymbol::Id()
    {
        return id_;
    }

    OPORDER OpSymbol::Order()
    {
        return order_;
    }

    std::string OpSymbol::Regex()
    {
        return escape_ ? std::string("\\") + id_ : id_;
    }
}