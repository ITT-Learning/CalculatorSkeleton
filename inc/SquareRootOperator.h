/**
 * @file SquareRootOperator.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef SQUAREROOTOPERATOR_H
#define SQUAREROOTOPERATOR_H

#include "IUnaryOperator.h"

namespace Calculator
{
    class SquareRootOperator : public IUnaryOperator
    {
        public:
            SquareRootOperator();
            ~SquareRootOperator();
            virtual double calculate(double input);
    };
}

#endif //SQUAREROOTOPERATOR_H