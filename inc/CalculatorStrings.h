/**
 * @file CalculatorStrings.h
 * @author Gary Dean Jenkins (gary.jenkins@intimetec.com)
 * @brief Strings and chars used in the Calculator project
 * @version 0.1
 * @date 2021-07-22
 * 
 * @copyright Cop.yright (c) 2021
 * 
 */

#ifndef CALCULATORSTRINGS_H
#define CALCULATORSTRINGS_H

namespace calculatorw2
{
    enum class Operators: char
    {
        UNKNOWN  = 'u',
        NOOP     = 'n',
        HELP     = 'h',
        QUIT     = 'q',
        ADD      = '+',
        SUBTRACT = '-',
        MULTIPLY = '*',
        DIVIDE   = '/'
    };

    const char helloMessage[] = "Gary's Calculator C++ learning project.";
    const char helpMessage[] = "Enter an expression, like 1 + 2 and ENTER. Valid operations are +-*/";
    const char quitMessage[] = "Quitting!";
    const char unknownOperationError[] = "Error: Unknown operation";
    const char divideByZeroError[] = "Error: Division by zero";
};

#endif  // CALCULATORSTRINGS_H