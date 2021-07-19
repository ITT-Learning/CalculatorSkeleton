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
void GetInput(char& operation, double& a, double& b) ;
double Calculate(char operation, double a, double b);
double Addition(double a, double b);
double Subtraction(double a, double b);
double Division(double a, double b);
double Multiplication(double a, double b);

#endif  // CALCULATOR_H