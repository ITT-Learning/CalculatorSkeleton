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

#include <regex>

#include "IUnaryOperator.h"

namespace Calculator
{
    IUnaryOperator::IUnaryOperator(OPORDER oporder, std::string opstring) :
        opstring_(opstring), IOperator(oporder, opstring + " [^ ]+") {}

    IUnaryOperator::~IUnaryOperator() {}

    bool IUnaryOperator::eval(std::string &input)
    {
        bool retv = false;

        std::string rgx_string = opstring_ + " ([^ ]+)";
        std::regex rgx(rgx_string);
        std::smatch sm;

        if (regex_search(input, sm, rgx)) 
        {
            double right = std::stod(sm[1]);
            double result = calculate(right);
            input = regex_replace(input, rgx, std::to_string(result));
            retv = true;
        }

        return retv;
    }
}