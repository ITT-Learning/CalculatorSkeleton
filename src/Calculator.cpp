////////////////////////////////////////////////////////////////////////////////
/**
* @file Calculator.cpp
* @brief Function definitions and class for calculator
*/
////////////////////////////////////////////////////////////////////////////////

#include "Calculator.h"
#include <stdlib.h>
#include <iomanip>
#include <string>
#include <iostream>
#include <typeinfo>

namespace calculator{

//*************/
// Calculator public methods /
///

    void Calculator::runCalculator(){
        // read input
        std::string input;
        getline(std::cin, input); //get input


        std::string num1;
        std::string num2;
        char op;

        std::string fullEquation;
        bool findingOperator=false;
        bool operatorFound=false;
        
        for (size_t i = 0; i < input.length(); i++)
        {

            if(input.at(i) == ' ')
            {
                continue;
            }

            if(std::isdigit(input.at(i)))
            {
                if (!operatorFound)
                {
                    num1 += input.at(i);
                    findingOperator = true;
                }
                if (operatorFound)
                {
                    num2 += input.at(i);
                }
                fullEquation += input.at(i);
                
            }

            else if(input.at(i) == '-') 
            {
                if (!findingOperator) //find negative num
                {
                    num1 += "-";
                    fullEquation += "-";
                    findingOperator=true;
                }
                else if (findingOperator) //find - operator
                {
                    fullEquation+='-';
                    op='-';
                    operatorFound= true;
                    findingOperator=false;
                }
            }
            else if(input.at(i) == '+') 
            {
                if (!findingOperator) //if num1 is positive
                {
                    continue;
                }
                if (findingOperator) //find operator
                {
                    if (!operatorFound){
                        op='+';
                        fullEquation+='+';
                        operatorFound=true;
                    }
                }
            }
        }

        std::cout <<"num1 is:" << num1 << std::endl;
        std::cout <<"num2 is:" << num2 << std::endl;
        std::cout <<"op is:" << op << std::endl;
        std::cout <<"full is:" << fullEquation << std::endl;
    
    }


    void Calculator::calculate(const char &operation, const double &num1, const double &num2){
        double answer;    
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