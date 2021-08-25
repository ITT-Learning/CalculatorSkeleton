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

#include "IHelper.h"
#include "ITraceable.h"
#include "OpSymbol.h"

namespace Calculator
{
    class IOperator : protected ITraceable, public IHelper
    {
        public:
            using CreateMethod = IOperator*(*)();
            
            IOperator(const OpSymbol opsymbol);
            ~IOperator();

            OpSymbol GetOpSymbol();

            virtual bool eval(std::string &input) = 0;
            virtual std::string findString() = 0;

        private:
            const OpSymbol opsymbol_;
    };
}

#endif //IOPERATOR_H