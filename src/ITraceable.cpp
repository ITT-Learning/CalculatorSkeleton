/**
 * @file ITraceable.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>

#include "../inc/ITraceable.h"

namespace Calculator
{
    ITraceable::ITraceable() {}

    ITraceable::~ITraceable() {}

    void ITraceable::SetTrace(bool trace)
    {
        trace_ = trace;
    }

    void ITraceable::Trace(std::string message)
    {
        if(trace_)
        {
            std::cout << "   " << message << std::endl;
        }
    }

    bool ITraceable::trace_ = false;
}