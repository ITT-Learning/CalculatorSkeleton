/**
 * @file AbsoluteOperator.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef ABSOLUTEOPERATOR_H
#define ABSOLUTEOPERATOR_H

#include "IUnaryOperator.h"

namespace Calculator
{
    class AbsoluteOperator : public IUnaryOperator
    {
        public:
            AbsoluteOperator();
            ~AbsoluteOperator();
            virtual double calculate(double input);
    };
}

#endif //ABSOLUTEOPERATOR_H