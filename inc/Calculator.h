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

#include <string>
#include <stack>

#include "IMathOperation.h"

class Calculator
{
    public:
        static double calculate(std::string equationString);
        static std::string sanitizeString(std::string unsanitizedString);

    private:
        Calculator(){};

        static IMathOperation* parseString(std::string equationString);
        static IMathOperation* extractOperation(std::stack<std::string>& postfixStack);
        static std::stack<std::string> infixToPostfix(std::string infixString);
};

#endif