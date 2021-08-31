////////////////////////////////////////////////////////////////////////////
/**
 *  @file   main.cpp
 *  @date   Fri August 25 2021
 *  @brief  Entry Point of Calculator
 */
////////////////////////////////////////////////////////////////////////////

#include "../inc/Calculator.h"


int main() 
{
    //This calculator can do super basic and simple math. 
    while(true)
    {
        char repeat; 
        std::cout << "Welcome to the Calculator C++ learning project." << std::endl;
        std::cout << "Please enter in two numbers separated by a space" << std::endl;
        calculator();
        std::cout << "Would you like to run the program again? y/n" << std::endl;
        std::cin >> repeat;
        if(repeat != 'y')
        {
            return 0;
        }
    }
}