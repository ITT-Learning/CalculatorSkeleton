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

#include "IMathOperation.h"
#include <string>
#include <stack>

class Calculator
{
    private:
        Calculator(){};

        static IMathOperation* parseString(std::string);
        static double parseNumber(std::string);
        static IMathOperation* extractOperation(std::stack<std::string>&);
        static std::stack<std::string> infixToPostfix(std::string);

    public:
        static double calculate(std::string);
        static std::string sanitizeString(std::string);
};

#endif