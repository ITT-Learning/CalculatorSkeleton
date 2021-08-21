/**
 * @file EvaluateOperator.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef EvaluateOperator_H
#define EvaluateOperator_H

#include "IOperator.h"

namespace Calculator
{
    class EvaluateOperator : public IOperator
    {
        public:
            EvaluateOperator();
            ~EvaluateOperator();
            virtual bool eval(std::string &input);
            virtual std::string findString();
    };
}

#endif //EvaluateOperator_H
