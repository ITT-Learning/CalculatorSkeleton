/**
 * @file TraceOperator.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef TRACEOPERATOR_H
#define TRACEOPERATOR_H

#include "IOperator.h"

namespace Calculator
{
    class TraceOperator : public IOperator
    {
        public:
            static bool REGISTEREDON;
            static bool REGISTEREDOFF;
            TraceOperator(OpSymbol os);
            ~TraceOperator();
            virtual bool eval(std::string &input);
            virtual std::string findString();
            virtual const std::string help();
    };
}

#endif //TRACEOPERATOR_H