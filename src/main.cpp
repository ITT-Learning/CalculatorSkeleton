////////////////////////////////////////////////////////////////////////////
/**
 *  @file   main.cpp
 *  @date   Fri August 25 2021
 *  @brief  This is a basic calculator program which asks for an equation and uses a switch to decifer what the equation is and return the result
 */
////////////////////////////////////////////////////////////////////////////

#include "../inc/Calculator.h"

using namespace calculator;
int main() 
{
    //This calculator can do super basic and simple math. 
    while(true)
    {
        char repeat; 
        Calculator calc;
        calc.calculate();
        std::cout << "Would you like to run the program again? y/n" << std::endl;
        std::cin >> repeat;
        if(repeat != 'y')
        {
            return 0;
        }
    }
}
