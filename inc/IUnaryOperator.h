/**
 * @file IUnaryOperator.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-18
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef IUNARYOPERATOR_H
#define IUNARYOPERATOR_H

#include "IOperator.h"

namespace Calculator
{
    class IUnaryOperator : public IOperator
    {
        public:
            IUnaryOperator(OpSymbol opsymbol);
            ~IUnaryOperator();
            virtual bool eval(std::string &input);
            virtual std::string findString();
            virtual double calculate(double right) = 0;
    };
}

#endif