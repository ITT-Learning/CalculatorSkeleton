////////////////////////////////////////////////////////////////////////////
/**
 *  @file   Calculator.cpp
 *  @date   Fri April 16 2021
 *  @brief  Funtions that support main.cpp
 */
////////////////////////////////////////////////////////////////////////////

#include "Calculator.h"

// Add Function definitions here.


class Calculator{
    public:
        float add(double num1, double num2){
            return num1 + num2;
        }
        float subtract(double num1, double num2){
            return num1 - num2;
        }
        float divide(double num1, double num2){
            return num1 / num2;
        }
        float multiply(double num1, double num2){
            return num1 * num2;
        }
};

void runCalc(){
    double num1;
    double num2;
    char calcType;

    std::cout << "Enter A number, an operator, and a number...\n";
    std::cin >> num1;
    std::cin >> calcType;
    std::cin >> num2;

    calc(calcType, num1, num2);
}

void calc(char calcType, double num1, double num2){
    double ans;
    Calculator c;
    
    switch (calcType)
    {
    case '+':
        ans = c.add(num1, num2);
    break;

    case '-':
        ans = c.subtract(num1, num2);
    break;

    case 'x':
        ans = c.multiply(num1, num2);
    break;

    case '*':
        ans = c.multiply(num1, num2);
    break;

    case '/':
        ans = c.divide(num1, num2);
    break;

    case '%':
        ans = c.divide(num1, num2);
    break;

    default:
        std::cout << "Incorrectly Entered, try 1 + 1.\n";
        return;
    }

    std::cout << num1 << " " << calcType << " " << num2 << " = " << ans << ".\n";
    }