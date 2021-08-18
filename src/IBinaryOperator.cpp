/**
 * @file IBinaryOperator.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-18
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <regex>

#include "IBinaryOperator.h"

namespace Calculator
{
    IBinaryOperator::IBinaryOperator(OpSymbol opsymbol) :
        IOperator(opsymbol) {}

    IBinaryOperator::~IBinaryOperator() {}

    bool IBinaryOperator::eval(std::string &input)
    {
        bool retv = false;

        std::string rgx_string = "([^& ]+) " + GetOpSymbol().Regex + " ([^ ]+)";
        std::regex rgx(rgx_string);
        std::smatch sm;

        if (regex_search(input, sm, rgx)) 
        {
            double left = std::stod(sm[1]);
            double right = std::stod(sm[2]);
            double result = calculate(left, right);
            input = regex_replace(input, rgx, std::to_string(result));
            retv = true;
        }

        return retv;
    }

    std::string IBinaryOperator::findString()
    {
        return "[^ ]+ (" + GetOpSymbol().Regex + ") [^ ]+";
    }
}