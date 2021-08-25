/**
 * @file ParenthesisOperator.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef PARENTHESISOPERATOR_H
#define PARENTHESISOPERATOR_H

#include "IOperator.h"

namespace Calculator
{
    class ParenthesisOperator : public IOperator
    {
        public:
            static bool REGISTERED;
            ParenthesisOperator();
            ~ParenthesisOperator();
            virtual bool eval(std::string &input);
            virtual std::string findString();
            virtual const std::string help();
    };
}

#endif //PARENTHESISOPERATOR_H