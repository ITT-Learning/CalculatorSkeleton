/**
 * @file IUnaryOperator.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-18
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <regex>

#include "IUnaryOperator.h"

namespace Calculator
{
    IUnaryOperator::IUnaryOperator(OpSymbol opsymbol) :
        IOperator(opsymbol) {}

    IUnaryOperator::~IUnaryOperator() {}

    bool IUnaryOperator::eval(std::string &input)
    {
        bool retv = false;

        std::string rgx_string = GetOpSymbol().Regex() + " *" + REGEX_DOUBLE_CAPTURE + " *";
        std::regex rgx(rgx_string);
        std::smatch sm;

        std::string result;

        if (regex_search(input, sm, rgx)) 
        {
            std::string rightStr = sm[1].str();
            double right = stod(rightStr);
            result = std::to_string(calculate(right));
            retv = true;
        }
        else
        {
            result = "UNKNOWN_ERROR[" + input + "]";
        }

        Trace(GetOpSymbol().Id() + " -> " + sm[0].str() + " = " + result);
        input = regex_replace(input, rgx, result);

        return retv;
    }

    std::string IUnaryOperator::findString()
    {
        return "(" + GetOpSymbol().Regex() + ") *" + REGEX_DOUBLE;
    }
}