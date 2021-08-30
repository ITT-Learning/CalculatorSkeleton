////////////////////////////////////////////////////////////////////////////////
/**
* @file Calculator.cpp
* @brief Function definitions and class for calculator
*/
////////////////////////////////////////////////////////////////////////////////

#include "Calculator.h"

namespace calculator{
    class Calculator{
        
        public:
            void calculate(const char &operation, const double &num1, const double &num2){
                double answer;

/**
 * @note regarding adding case brackets, it looks like this is expected switch statement form 
 * per page 26 of the dune guidelines, 
 * unless there's another reason for case brackets
 * */
                     
            switch (operation)
            {
            case '+':
                answer = add(num1, num2);
                break;
            case '-':
                answer = subtract(num1, num2);
                break;
            case 'x':
                answer = multiply(num1, num2);
                break;
            case '*':
                answer = multiply(num1, num2);
                break;
            case '/':
                answer = divide(num1, num2);
                break;
            case '%':
                answer = divide(num1, num2);
                break;
            default:
                std::cout << "Incorrectly Entered, try 1 + 1.\n";
                return;
        }

            std::cout << num1 << " " << operation << " " << num2 << " = " << answer << ".\n";
        }

//*************/
// Calculator private methods /
///

        private:
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