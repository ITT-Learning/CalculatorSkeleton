////////////////////////////////////////////////////////////////////////////
/**
 *  @file   main.cpp
 *  @brief  Entry Point of Calculator
 */
////////////////////////////////////////////////////////////////////////////

#include "Calculator.h"
#include <iostream>

int main() 
{
    /**
     * @brief Calculates two entered numbers, including division, multiplication, adding, and subtracting.
     * @note User must enter following this order: "1 + 1"
     * @return Will return what user entered along with answer. ex: "1 + 1 = 2"
     * @note If incorrectly entered, user is prompted with "Incorrectly Entered, try 1 + 1."
    */
char answer;
    calculator::Calculator c;

    while (true)
    {
        c.runCalculator();
        


        // std::cout << "Run again? (y/n)" << std::endl;
        // std::cin >> answer;
        // if (answer != 'y'){
        //     return 0;
        // }
    }

    
    

    
}