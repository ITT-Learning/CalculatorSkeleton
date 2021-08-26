/**
 * @file HelpOperator.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <regex>

#include "HelpOperator.h"
#include "OperatorFactory.h"

namespace Calculator
{
    bool HelpOperator::REGISTERED = OperatorFactory::GetInstance()->RegisterOperator(new HelpOperator);

    HelpOperator::HelpOperator() :
        IOperator(OpSymbol("help", OPORDER::ZERO)), factory_(OperatorFactory::GetInstance()) {}

    HelpOperator::~HelpOperator() {}

    bool HelpOperator::eval(std::string &input)
    {
        bool retv = false;

        std::string rgx_string = GetOpSymbol().Regex() + "( *)?([^ ]+)?";
        std::regex rgx(rgx_string);
        std::smatch sm;

        if (regex_search(input, sm, rgx)) 
        {
            std::string opId = sm[2].str();
            IOperator* op = factory_->GetOperator(opId);

            if (opId.empty())
            {
                input = help();
            }
            else if (op == nullptr)
            {
                input = "HELP Error: Unknown Operator";
            }
            else
            {
                input = op->help();
            }
        }

        return retv;
    }
    
    std::string HelpOperator::findString()
    {
        return "(help)(?: [^ ]+)?";
    }

    const std::string HelpOperator::help()
    {
        std::string retv = 
            "\n\nWelcome to the command line calculator for arbitrarily "
            "complex math equations using floating point numbers. Enter an "
            "equation using numbers and operators. At the end of the equation "
            "hit enter to evaluate the equation."
            "\n\n\t\"calculator>\" is waiting for an equation to calculate."
            "\n\t\"calculator=\" is followed by the result of a calculation"
            " or operation.\n\nThe following are the "
            "supported equations and their order of operation ...\n";
        retv += ("\tOrder\tOperations\n");
        for (OPORDER order : factory_->GetOpOrders())
        {
            retv += ( "\t" + std::to_string(order) + "\t");
            std::string sep = "";
            for (const std::string oplist : *factory_->GetOperatorListByOpOrder(order))
            {
                retv += ( sep + oplist );
                sep = ", ";
            }
            retv += "\n";
        }
        
        retv += "\nTo get more help on an operator. Type help followed by the operator and hit enter. ex. \"help +\"";

        return retv;
    }
}