///////////////////////////////////////////////////////////////////////////////
/**
 * @file  Calculator.h
 * @date  Fri, 16 April 2021
 * @brief 
 * 
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
// Add your function declarations here.

class Calculator {
    public:

        //when adding Operations make sure to add them to validOperations_ as well
        enum class Operation: char
        {
            ADD      = '+',
            DIVIDE   = '/',
            MULTIPLY = '*',
            SUBTRACT = '-'
        };

        Calculator();

        explicit Calculator(const std::string &mathExpression);
        explicit Calculator(int a, int b, Operation operation);

        ~Calculator();

        int getResult();

        //void setExpression(int a, int b, Operation operation);
        //void setExpression(const std::string &mathExpression);
        
    private:
        int a_                             = 0;
        int b_                             = 0;
        int result_                        = 0;
        Operation operation_               = Operation::ADD;
        bool hasError_                     = false;
        std::string errorMessage_          = "";
        std::vector<char> validOperations_ { (char)Operation::ADD,
                                             (char)Operation::SUBTRACT,
                                             (char)Operation::MULTIPLY, 
                                             (char)Operation::DIVIDE };
        
        int add(int a, int b);
        int divide(int a, int b);
        int multiply(int a, int b);
        int subtract(int a, int b);
        
        void calculateResult();

        friend std::string to_string(const Calculator&);
        friend std::ostream& operator<<(std::ostream& os, const Calculator&);
};
#endif  // CALCULATOR_H
