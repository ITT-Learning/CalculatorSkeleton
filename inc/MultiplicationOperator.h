/**
 * @file MultiplicationOperator.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef MULTIPLICATIONOPERATOR_H
#define MULTIPLICATIONOPERATOR_H

#include "IBinaryOperator.h"

namespace Calculator
{
    class MultiplicationOperator : public IBinaryOperator
    {
        public:
            MultiplicationOperator();
            ~MultiplicationOperator();
            virtual double calculate(double left, double right); 
    };
}

#endif //MULTIPLICATIONOPERATOR_H