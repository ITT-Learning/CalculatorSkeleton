/**
 * @file ExponentOperator.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef EXPONENTOPERATOR_H
#define EXPONENTOPERATOR_H

#include "IBinaryOperator.h"

namespace Calculator
{
    class ExponentOperator : public IBinaryOperator
    {
        public:
            static bool REGISTERED;
            ExponentOperator();
            ~ExponentOperator();
            virtual double calculate(double left, double right); 
    };
}

#endif //EXPONENTOPERATOR_H