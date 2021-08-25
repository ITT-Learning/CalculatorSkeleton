/**
 * @file InverseOperator.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef INVERSEOPERATOR_H
#define INVERSEOPERATOR_H

#include "IUnaryOperator.h"

namespace Calculator
{
    class InverseOperator : public IUnaryOperator
    {
        public:
            static bool REGISTERED;
            InverseOperator();
            ~InverseOperator();
            virtual double calculate(double input);
            virtual const std::string help();
    };
}

#endif //INVERSEOPERATOR_H