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
#include "OperatorFactory.h"

namespace Calculator
{
    EvaluateOperator::EvaluateOperator() :
        IOperator(OpSymbol("eval",OPORDER::ZERO)) {}

    EvaluateOperator::~EvaluateOperator() {}

    bool EvaluateOperator::eval(std::string &input)
    {
        //std::cout << "EvaluateOperator::eval(" << input << ")" << std::endl;
        OperatorFactory *opFactory = OperatorFactory::GetInstance();
        for (OPORDER order : opFactory->GetOpOrders())
        {
            std::vector<std::string>* opIds = opFactory->GetOperatorListByOpOrder(order);
            //std::cout << "operators(" << opIds << ")" << std::endl;

            if (!opIds->empty())
            {
                //std::cout << "  size:" << opIds->size() << std::endl;

                std::string rgxString, sep;
                std::for_each(opIds->begin(), opIds->end(), [&](const std::string &opId)
                { 
                    rgxString += (sep + opFactory->GetOperator(opId)->findString());
                    sep = "|";
                });

                //std::cout << "  rgxString:\"" << rgxString << "\"" << std::endl;

                std::smatch sm;
                std::regex rgx(rgxString);
                while (regex_search(input, sm, rgx)) 
                {
                    //std::cout << "  eval(" << input << "|" << sm[0].str()  << "|" << sm[1].str() << ")" << std::endl;
                    std::string fndop;
                    for (unsigned i = 1; i<sm.size(); i++) fndop += sm[i].str();
                    opFactory->GetOperator(fndop)->eval(input);
                    //std::cout << "  result:\"" << fndop << "|" << input << "\"\n";
                }
            }

            // std::cout << "rgx_operators(" << order << ")size:" << rgx_operators->size() << std::endl;
            // if (!rgx_operators->empty())
            // {
            //     std::string s;
            //     std::for_each(rgx_operators->begin(), rgx_operators->end(), [&](const std::string &piece){ s += piece; });
            //     std::cout << "rgx_operators(" << s << ")" << std::endl;

            //     std::smatch sm;
            //     std::regex rgx(s);

            //     while (regex_search(input, sm, rgx)) 
            //     {
            //         std::cout << "eval(" << input << "|" << sm[1] << ")" << std::endl;
            //         opFactory->GetOperator(sm[1])->eval(input);
            //     }
            // }
        }
        
        return true;
    }

    std::string EvaluateOperator::findString()
    {
        return "(" + GetOpSymbol().Regex() + ") ";
    }
}