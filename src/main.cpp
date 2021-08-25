////////////////////////////////////////////////////////////////////////////
/**
 *  @file   main.cpp
 *  @date   Fri April 16 2021
 *  @brief  Entry Point of Calculator
 */
////////////////////////////////////////////////////////////////////////////

#include "../inc/Calculator.h"
#include "../inc/OperatorFactory.h"

int main() 
{
    // Fill in or change code here as necessary.  See also Calculator.cpp
    std::cout << "Welcome to the Calculator C++ learning project." << std::endl;

    std::string input = "abs(1 - 3)";
    Calculator::OperatorFactory::GetInstance()->GetOperator("eval")->eval(input);
    std::cout << "= " << input << std::endl;

    input = "tron abs (1 - 3) troff"; //"((1 + 2) * 4) - 8";
    Calculator::OperatorFactory::GetInstance()->GetOperator("eval")->eval(input);
    std::cout << "= " << input << std::endl;

    input = "((1 + 2) * 4) - 8";
    Calculator::OperatorFactory::GetInstance()->GetOperator("eval")->eval(input);
    std::cout << "= " << input << std::endl;

    // input = "trace+ 1 + 2";
    // Calculator::OperatorFactory::GetInstance()->GetOperator("eval")->eval(input);
    // std::cout << "= " << input << std::endl;
}
