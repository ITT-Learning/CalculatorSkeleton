////////////////////////////////////////////////////////////////////////////
/**
 *  @file   main.cpp
 *  @date   Fri April 16 2021
 *  @brief  Entry Point of Calculator
 */
////////////////////////////////////////////////////////////////////////////

#include "Calculator.h"

int main() 
{
        /**
 * @brief Calculates two entered numbers, including division, multiplication, adding, and subtracting.
 * @param num1 is first number entered
 * @param num2 is second number entered
 * @param operation is the operator entered (+, - , / or % , * or x)
 * @note user must enter following this order: "1 + 1"
 * @return Will return what user entered along with answer. ex: "1 + 1 = 2"
 * @note if incorrectly entered, user is prompted with "Incorrectly Entered, try 1 + 1."
    **/

    calculator::runCalculator();
}



