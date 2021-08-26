////////////////////////////////////////////////////////////////////////////
/**
 *  @file   Calculator.cpp
 *  @date   Fri April 16 2021
 *  @brief  Funtions that support main.cpp
 */
////////////////////////////////////////////////////////////////////////////

#include "Calculator.h"

namespace Calculator
{
    Calculator::Calculator(std::istream &ccin, std::ostream &ccout) :
        ccin_(ccin), ccout_(ccout), factory_(OperatorFactory::GetInstance()) {}

    Calculator::~Calculator() {}

    void Calculator::run()
    {
        bool run = true;
        std::string input = "";

        while (input != "quit")
        {
            ccout_ << "calculator> " << std::flush;
            std::getline(ccin_, input);

            factory_->GetOperator("eval")->eval(input);
            
            ccout_ << "calculator= " << input << std::endl;
        }
    }
}