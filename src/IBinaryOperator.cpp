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

        std::string rgx_string = REGEX_DOUBLE_CAPTURE + " *" + GetOpSymbol().Regex() + " *" + REGEX_DOUBLE_CAPTURE;
        std::regex rgx(rgx_string);
        std::smatch sm;

        std::string result;

        if (regex_search(input, sm, rgx)) 
        {
            std::string leftStr = sm[1].str();
            std::string rightStr = sm[3].str();

                double left = std::stod(leftStr);
                double right = std::stod(rightStr);
                result = std::to_string(calculate(left, right));

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

    std::string IBinaryOperator::findString()
    {
        return REGEX_DOUBLE + " *(" + GetOpSymbol().Regex() + ") *" + REGEX_DOUBLE;
    }
}