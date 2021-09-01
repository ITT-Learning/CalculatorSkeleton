////////////////////////////////////////////////////////////////////////////
/**
 *  @file   main.cpp
 *  @date   Fri August 25 2021
 *  @brief  This is a basic calculator program which asks for two numbers and it returns the a couple equations using those numbers. 
 */
////////////////////////////////////////////////////////////////////////////

#include "../inc/Calculator.h"


int main() 
{
    //This calculator can do super basic and simple math. 
    while(true)
    {
        char repeat; 
        Calculator::Week1 week1;
        week1.calculator();
        std::cout << "Would you like to run the program again? y/n" << std::endl;
        std::cin >> repeat;
        if(repeat != 'y')
        {
            return 0;
        }
    }
}
