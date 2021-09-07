#include "Calculator.h"
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////
/**
* @file Calculator.cpp
* @brief Function definitions and class for calculator
*/
////////////////////////////////////////////////////////////////////////////////
namespace calculator{

//*************/
// Calculator public methods /
///

    void Calculator::runCalculator(){
        double num1;
        double num2;
        char operation;

        std::cout << "Enter A number, an operator, and a number... (q to quit)\n";
        std::cin >> num1;
        std::cin >> operation;
        std::cin >> num2;

        Calculator::calculate(operation, num1, num2);
        
    }

    void Calculator::calculate(const char &operation, const double &num1, const double &num2){
        double answer;
        bool running = true;
        

            switch (operation)
            {
            case '+':
                {
                answer = add(num1, num2);
                break;
                }
            case '-':
                {
                answer = subtract(num1, num2);
                break;
                }
            case 'x':
                {
                answer = multiply(num1, num2);
                break;
                }
            case '*':
                {
                answer = multiply(num1, num2);
                break;
                }
            case '/':
                {
                answer = divide(num1, num2);
                break;
                }
            case '%':
                {
                answer = divide(num1, num2);
                break;
                }
            default:
                std::cout << "Incorrectly Entered, try 1 + 1.\n";
            }

            std::cout << num1 << " " << operation << " " << num2 << " = " << answer << ".\n";
            }

    


//*************/
// Calculator private methods /
///
    float Calculator::add(double num1, double num2){
        return num1 + num2;
    }
    float Calculator::subtract(double num1, double num2){
        return num1 - num2;
    }
    float Calculator::divide(double num1, double num2){
        return num1 / num2;
    }
    float Calculator::multiply(double num1, double num2){
        return num1 * num2;
    }

}//namespace calculator