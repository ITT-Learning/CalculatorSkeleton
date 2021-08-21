/**
 * @file ParenthesisOperator.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <regex>
#include <iostream>

#include "ParenthesisOperator.h"
#include "OperatorFactory.h"

namespace Calculator
{
    bool ParenthesisOperator::REGISTERED = OperatorFactory::GetInstance()->RegisterOperator(new ParenthesisOperator);

    ParenthesisOperator::ParenthesisOperator() : 
        IOperator(OpSymbol("(", OPORDER::ONE, true)) {}

    ParenthesisOperator::~ParenthesisOperator() {}

    bool ParenthesisOperator::eval(std::string &input)
    {
        bool retv = false;

        std::string rgx_string = GetOpSymbol().Regex() + "([^\\(\\)]+)\\)";
        std::regex rgx(rgx_string);
        std::smatch sm;

        if (regex_search(input, sm, rgx)) 
        {
            auto evaluator = OperatorFactory::GetInstance()->GetOperator("eval");
            std::string expression = sm[1];
            retv = evaluator->eval(expression);
            input = regex_replace(input, rgx, expression, std::regex_constants::format_first_only);
        }

        return retv;
    }

    std::string ParenthesisOperator::findString()
    {
        return "(" + GetOpSymbol().Regex() + ")[^\\(\\)]+\\)";
    }
}