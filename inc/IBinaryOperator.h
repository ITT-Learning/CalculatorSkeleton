/**
 * @file IBinaryOperator.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-18
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef IBINARYOPERATOR_H
#define IBINARYOPERATOR_H

#include "IOperator.h"

namespace Calculator
{
    class IBinaryOperator : public IOperator
    {
        public:
            IBinaryOperator(OpSymbol opsymbol);
            ~IBinaryOperator();
            virtual bool eval(std::string &input);
            virtual std::string findString();
            virtual double calculate(double left, double right) = 0;
    };
}

#endif