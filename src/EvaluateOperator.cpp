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

#include "EvaluateOperator.h"

namespace Calculator
{
    EvaluateOperator::EvaluateOperator() :
        IOperator(OpSymbol("eval",OPORDER::ZERO)), opfactory_(OperatorFactory::GetInstance()) {}

    EvaluateOperator::~EvaluateOperator() {}

    bool EvaluateOperator::eval(std::string &input)
    {
        for (OPORDER opOrder : opfactory_->GetOpOrders())
        {
            evalOpOrder(opOrder, input);
        }
        
        return true;
    }

    bool EvaluateOperator::evalOpOrder(OPORDER opOrder, std::string&input) 
    {
        std::string rgxString = GetRegStringFromOpOrder(opOrder);
        if (!rgxString.empty())
        {
            EvaluateWithRegex(rgxString, input);
        }

        return true;    
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
        std::smatch sm;
        std::regex rgx(rgxString);
        
        while (regex_search(input, sm, rgx)) 
        {
            std::string fndop;
            for (unsigned i = 1; i<sm.size(); i++) fndop += sm[i].str();
            opfactory_->GetOperator(fndop)->eval(input);
        }

        return true;
    }

}