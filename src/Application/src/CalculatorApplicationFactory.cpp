
/**
 * @file CalculatorApplicationFactory.cpp
 * @brief 
 * @version 0.1
 * @date 2021-10-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <sstream>

#include "DivideCalculator.h"
#include "AddCalculator.h"
#include "MultiplyCalculator.h"
#include "CalculatorApplicationFactory.h"
#include "SubtractCalculator.h"

namespace calculator
{
    std::unique_ptr<ICalculator> CalculatorApplicationFactory::createCalculator(float a, float b, char op)
    {
        std::unique_ptr<ICalculator> result = nullptr; //create calculator type pointer and point to null
        



            switch (op) //switch case decides which calculator to return 
            {
                case '+':
                {
                    result = std::unique_ptr<ICalculator>(new AddCalculator(a, b));
                    break;
                }
                case '-':
                {
                    result = std::unique_ptr<ICalculator>(new SubtractCalculator(a, b));
                    break;
                }
                case '*':
                {
                    result = std::unique_ptr<ICalculator>(new MultiplyCalculator(a, b));
                    break;
                }
                case '/':
                {
                    result = std::unique_ptr<ICalculator>(new DivideCalculator(a, b));
                    break;
                } 
                default:
                {
                    result = nullptr; //if operator doesn't meet one of the cases, return pointing to null
                }
            }
            return result; 
        }    
}
