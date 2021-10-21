/**
 * @file CalculatorApplicationFactory.h
 * @brief Factory Pattern class
 * @version 0.1
 * @date 2021-10-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef CALCULATORAPPLICATIONFACTORY_H
#define CALCULATORAPPLICATIONFACTORY_H

#include <memory>

#include "ICalculator.h"
#include "ICalculatorFactory.h"
namespace calculator 
{
    class CalculatorApplicationFactory : ICalculatorFactory
    {
        public:
            /**
             * @brief Create a Calculator object
             * 
             * @param a first number
             * @param b second number
             * @param ops char operator
             * @return std::unique_ptr<ICalculator> 
             */
            std::unique_ptr<ICalculator> createCalculator(float a, float b, char ops) override;
    };
}
#endif  // CALCULATORAPPLICATIONFACTORY_H
