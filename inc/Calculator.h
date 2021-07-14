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

//Method to call from main. Loops until error/state > 0
void RunCalculator(); 
const char* GetInput(char& operation, double& a, double& b);
const char* Calculate(char operation, double a, double b, double& result);

#endif  // CALCULATOR_H