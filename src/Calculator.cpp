////////////////////////////////////////////////////////////////////////////
/**
 *  @file   Calculator.cpp
 *  @date   Fri April 16 2021
 *  @brief  Funtions that support main.cpp
 */
////////////////////////////////////////////////////////////////////////////

#include "Calculator.h"
namespace calculator 
{
    void printCalculations(const int &a, const int &b)
    {
        std::cout << std::endl;
        std::cout << formatCalculation(a, b, a + b, '+') << std::endl;
        std::cout << formatCalculation(a, b, a * b, 'X') << std::endl;
        std::cout << formatCalculation(a, b, b == 0 ? 0 : a / b, '%') << std::endl;
        std::cout << formatCalculation(a, b, a - b, '-') << std::endl;
    }

    std::string formatCalculation(const int &a, const int &b, const int &result, char operation)
    {
        //Sanity check if a control character gets inserted
        operation = isprint(int(operation)) ? operation : UNKNOWN_OPERATION;

        return "" + std::to_string(a) + " " + operation + " " + std::to_string(b) + " = " + std::to_string(result);
    }
}//namespace calculator