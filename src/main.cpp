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

<<<<<<< HEAD
=======
    Calculator calc;

    std::cout << calc.hello() << std::endl;
>>>>>>> ef987d43c131cce18f53162efa2b96e782a97cf8

    
    float number1, number2;
    std::cout << "Welcome to the Calculator C++ learning project." << std::endl;
    std::cout << "Please enter in two numbers separated by a space" << std::endl;
    std::cin >> number1 >> number2;
    int addResult = number1 + number2;
    int multiplyResult = number1 * number2;
    float divideResult = number1 / number2;
    int subtractResult = number1 - number2;
    std::cout << number1 << " + " << number2 << " = " << addResult << std::endl; 
    std::cout << number1 << " X " << number2 << " = " << multiplyResult << std::endl;
    std::cout << number1 << " % " << number2 << " = " << divideResult << std::endl;
    std::cout << number1 << " - " << number2 << " = " << subtractResult << std::endl;

    

    //here is the end of the program 

<<<<<<< HEAD

=======
    //testing
>>>>>>> ef987d43c131cce18f53162efa2b96e782a97cf8
}
