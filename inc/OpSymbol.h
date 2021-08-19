/**
 * @file OpSymbol.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef OPSYMBOL_H
#define OPSYMBOL_H

#include <string>

#include "CalculatorResources.h"

namespace Calculator
{
    class OpSymbol
    {
        public:
            OpSymbol(std::string id, OPORDER order, bool escape = false);
            ~OpSymbol();
            std::string Id();
            OPORDER Order();
            std::string Regex();
        private:
            bool escape_;
            std::string id_;
            OPORDER order_;
    };
}

#endif