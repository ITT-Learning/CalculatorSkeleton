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

namespace calculator 
{
    /**
     * @brief This is the entry method for running the calculator from main
     * 
     */
    void RunCalculator();

    /**
     * @brief Get the Input values from the user for the calculation. The user input is of the forms ...
     *      a + b
     *      a - b
     *      a * b
     *      a / b
     *      q - results in termination of the calculator
     * @note Methods return a nullptr when complete, or a char* to an error message when in error
     * @param operation [out] the math operation to be calculated (+ - * /)
     * @param a [out] the left term of the equation
     * @param b [out] the right term of the equation
     * @param input [in] the input stream. default to cin for users. available for testing.
     * @return const char* = nullptr if successful, descriptitve string if there was an error
     */
    const char* GetInput(char& operation, double& a, double& b, std::istream& input = std::cin) ;

    /**
     * @brief Given the inputs (operation, left term, right term) perform the calculation
     * @note throws an exception for divide by zero
     * @param [in] operation math function to perform
     * @param [in] a left term
     * @param [in] b right term
     * @param [out] result of the equation
     * @return const char* = nullptr if successful, descriptitve string if there was an error
     */
    const char* Calculate(const char& operation, const double a, const double b, double& result);

    /**
     * @brief Outputs the result to the specified stream
     * 
     * @param [in] result the result value calculated
     * @param [out] output output stream to write to. default is cout for users. provided for testing.
     */
    void OutputResult(const double& result, std::ostream& output = std::cout);

    /**
     * @brief Used to print an error condition instead of calculated value.
     * @note uses e.what() to get error string
     * @param e [in] standard exception
     * @param output [out] output stream to write to. default is cout for users. provided for testing.
     */
    void OutputError(const char* errorString, std::ostream& output = std::cout);
}

#endif  // CALCULATOR_H