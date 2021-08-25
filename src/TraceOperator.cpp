/**
 * @file TraceOperator.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <regex>
#include <iostream>
#include "TraceOperator.h"
#include "OperatorFactory.h"

namespace Calculator
{
    bool TraceOperator::REGISTEREDON = OperatorFactory::GetInstance()->RegisterOperator(new TraceOperator(OpSymbol("tron", OPORDER::ONE)));
    bool TraceOperator::REGISTEREDOFF = OperatorFactory::GetInstance()->RegisterOperator(new TraceOperator(OpSymbol("troff", OPORDER::SIX)));
           
    TraceOperator::TraceOperator(OpSymbol os) : 
        IOperator(os) {}

    TraceOperator::~TraceOperator() {}

    bool TraceOperator::eval(std::string &input)
    {
        bool retv = false;

        std::string rgx_string = " *(" + GetOpSymbol().Regex() + ") *";
        std::regex rgx(rgx_string);
        std::smatch sm;

        if (regex_search(input, sm, rgx)) 
        {
            SetTrace(sm[1].str() == "tron");
            Trace(input);
            input = regex_replace(input, rgx, "");
            retv = true;
        }

        return retv;
    }

    std::string TraceOperator::findString()
    {
        return  " *(" + GetOpSymbol().Regex() + ") *";
    }

    const std::string TraceOperator::help()
    {
        return HELP_TRACE_OPERATOR;
    }
}