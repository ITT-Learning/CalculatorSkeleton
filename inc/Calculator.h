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
#include <string>
// Add your function declarations here.
namespace calculator {
    /**
     * @brief character to use if unknown operation is used,
     *        typically if a control character is passed somehow
     * 
     */
    constexpr char UNKNOWN_OPERATION = ' ';

    /**
     * @brief prints to standard out basic arithmitic of two numbers formatted like:
     *        > 5 + 5 = 10
     *        > 5 X 5 = 25
     *        > 5 % 5 = 1
     *        > 5 - 5 = 0 
     * @note there is logic in place to prevent divide by zero error, the result will be a 0 instead
     * @param a [in] the left term of the math expression 
     * @param b [in] the right term of the math expression
     * 
     */
    void printCalculations(const int &a, const int &b);

    /**
     * @brief formats the arguments into a math expression as "[a] [operation] [b] = [result]"
     * @note there is no logic to check if the expression is valid. This only formats the arguments into an expression
     * @param a [in] left term of the math expression
     * @param b [in] right term of the math expression
     * @param result [in] result of the math expression, placed on the right of the '='
     * @param operation [in] math operation 
     * @return std::string formatted math equation
     *                     if a = 10, b = 4, operation = '-', and result = 6 
     *                     then return "10 - 4 = 6"
     * 
     */
    std::string formatCalculation(const int &a, const int &b, const int &result, char operation);

} // namespace calculator
#endif  // CALCULATOR_H