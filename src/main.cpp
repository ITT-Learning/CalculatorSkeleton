#include "Calculator.h"

////////////////////////////////////////////////////////////////////////////
/**
 *  @file   main.cpp
 *  @brief  Entry Point of Calculator
 */
////////////////////////////////////////////////////////////////////////////

int main() 
{
    /**
     * @brief Calculates two entered numbers, including division, multiplication, adding, and subtracting.
     * @note User must enter following this order: "1 + 1"
     * @return Will return what user entered along with answer. ex: "1 + 1 = 2"
     * @note If incorrectly entered, user is prompted with "Incorrectly Entered, try 1 + 1."
    */
    calculator::Calculator c;
    c.runCalculator();
}