////////////////////////////////////////////////////////////////////////////
/**
 *  @file   Calculator.cpp
 *  @date   Fri April 16 2021
 *  @brief  Funtions that support main.cpp
 */
////////////////////////////////////////////////////////////////////////////

#include "Calculator.h"

namespace calculator{
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
            
            
            void calculate(const char &operation, const double &num1, const double &num2){
                double ans = 0;
               
                
                switch (operation)
                {
                case '+':
                    {ans = add(num1, num2);
                    break;}
                case '-':
                    {ans = subtract(num1, num2);
                    break;}
                case 'x':
                    {ans = multiply(num1, num2);
                    break;}
                case '*':
                    {ans = multiply(num1, num2);
                    break;}
                case '/':
                    {ans = divide(num1, num2);
                    break;}
                case '%':
                    {ans = divide(num1, num2);
                    break;}

                default:
                    std::cout << "Incorrectly Entered, try 1 + 1.\n";
                    return;
                }

                std::cout << num1 << " " << operation << " " << num2 << " = " << ans << ".\n";
            }

        };

        void runCalculator(){
            double num1;
            double num2;
            char operation;

            std::cout << "Enter A number, an operator, and a number...\n";
            std::cin >> num1;
            std::cin >> operation;
            std::cin >> num2;

            Calculator c;
            c.calculate(operation, num1, num2);
        }



       
        
}//namespace calculator