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

        static std::stack<std::string> infixToPostfix(std::string);

        static std::string stringStart(std::string, int);
        static std::string stringEnd(std::string, int);

        static double extractLhs(std::string);
        static double extractRhs(std::string);

        static std::string compactString(std::string);

    public:
        static double calculate(std::string);
};

#endif