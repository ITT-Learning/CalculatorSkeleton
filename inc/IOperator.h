/**
 * @file IOperator.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-18
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef IOPERATOR_H
#define IOPERATOR_H

#include <string>
#include "CalculatorResources.h"

namespace Calculator
{
    class IOperator
    {
        public:
            IOperator(OPORDER oporder, std::string opregex);
            ~IOperator();

            OPORDER OpOrder();
            std::string OpRegex();

            virtual bool eval(std::string &input) = 0;

        private:
            OPORDER oporder_;
            std::string opregex_;
    };
}

#endif //IOPERATOR_H