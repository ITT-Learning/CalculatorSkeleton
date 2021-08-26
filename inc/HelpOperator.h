/**
 * @file HelpOperator.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef HELPOPERATOR_H
#define HELPOPERATOR_H

#include "IOperator.h"
#include "OperatorFactory.h"

namespace Calculator
{
    class HelpOperator: public IOperator
    {
        public:
            static bool REGISTERED;
            HelpOperator();
            ~HelpOperator();
            virtual bool eval(std::string &input);
            virtual std::string findString();
            virtual const std::string help();
        private:
            OperatorFactory *factory_;
    };
}

#endif //HELPOPERATOR_H