///////////////////////////////////////////////////////////////////////////////
/**
 * @file  Calculator.h
 * @date  Fri, 16 April 2021
 * @brief 
 * 
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>

#include "OperatorFactory.h"

namespace Calculator
{
    class Calculator
    {
        public:
            Calculator(std::istream &ccin = std::cin, std::ostream &ccout = std::cout);
            ~Calculator();
            void run();
        private:
            std::istream &ccin_;
            std::ostream &ccout_;
            OperatorFactory *factory_;
    };
}

#endif  // CALCULATOR_H