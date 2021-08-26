/**
 * @file EvaluateOperator.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <regex>
#include <string>

#include "EvaluateOperator.h"

namespace Calculator
{
    bool EvaluateOperator::REGISTERED = OperatorFactory::GetInstance()->RegisterOperator(new EvaluateOperator);

    EvaluateOperator::EvaluateOperator() :
        IOperator(OpSymbol("eval",OPORDER::ZERO)), opfactory_(OperatorFactory::GetInstance()) {}

    EvaluateOperator::~EvaluateOperator() {}

    bool EvaluateOperator::eval(std::string &input)
    {
        bool retv = true;

        for (OPORDER opOrder : opfactory_->GetOpOrders())
        {
            retv = evalOpOrder(opOrder, input);
            if ( !retv) break;          
        }

        return retv;
    }

    bool EvaluateOperator::evalOpOrder(OPORDER opOrder, std::string&input) 
    {
        bool retv = true;

        std::string rgxString = GetRegStringFromOpOrder(opOrder);
        if (!rgxString.empty())
        {
            retv = EvaluateWithRegex(rgxString, input);
        }

        return retv;    
    }

    std::string EvaluateOperator::findString()
    {
        return "(" + GetOpSymbol().Regex() + ") ";
    }

    std::string EvaluateOperator::GetRegStringFromOpOrder(OPORDER opOrder)
    {
        std::string rgxString = "";
        std::vector<std::string>* opIds = opfactory_->GetOperatorListByOpOrder(opOrder);

        if (!opIds->empty())
        {
            std::string sep = "";
            std::for_each(opIds->begin(), opIds->end(), [&](const std::string &opId)
            { 
                rgxString += (sep + opfactory_->GetOperator(opId)->findString());
                sep = "|";
            });
        }

        return rgxString;
    }

    bool EvaluateOperator::EvaluateWithRegex(const std::string &rgxString, std::string &input)
    {
        bool retv = true;

        std::smatch sm;
        std::regex rgx(rgxString);
        
        while (retv && regex_search(input, sm, rgx)) 
        {
            std::string fndop;
            for (unsigned i = 1; i<sm.size(); i++) fndop += sm[i].str();
            retv = opfactory_->GetOperator(fndop)->eval(input);
        }

        return retv;
    }

    const std::string EvaluateOperator::help()
    {
        return HELP_EVALUATE_OPERATOR;
    }
}