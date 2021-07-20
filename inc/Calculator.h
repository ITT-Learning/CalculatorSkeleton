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
    void RunCalculator();
    void GetInput(char& operation, double& a, double& b) ;
    double Calculate(char& operation, double a, double b);
    void OutputResult(double& result, std::ostream& out = std::cout);
    void OutputError(const std::exception& e, std::ostream& out = std::cout);
}

#endif  // CALCULATOR_H