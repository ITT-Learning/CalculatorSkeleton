////////////////////////////////////////////////////////////////////////////
/**
 *  @file   main.cpp
 *  @date   Fri August 25 2021
 *  @brief  This is a basic calculator program which asks for an equation and uses a switch to decifer what the equation is and return the result
 */
////////////////////////////////////////////////////////////////////////////

#include <iostream>

#include "../Application/inc/CalculatorApplication.h"

using namespace calculator;

int main() 
{
    //This calculator can do super basic and simple math. 
    while(true)
    {
        char repeat; 

        std::cout << CalculatorStrings::WELCOME_MESSAGE << std::endl;
        std::cout << CalculatorStrings::ENTER_EQUATION << std::endl;
        
        float firstNumber, secondNumber; 
        char op;

        std::cin >> firstNumber >> op >> secondNumber; // user inputs first number, operator, and second number
        
        CalculatorApplication::calculate(firstNumber, secondNumber, op);
        std::cout << "Would you like to run the program again? y/n" << std::endl;
        std::cin >> repeat;
        if(repeat != 'y')
        {
            return 0;
        }
    }
}
