/**
 * @file ICalculatorFactory.h
 * @brief Factory Interface used by main
 * @version 0.1
 * @date 2021-10-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef ICALCULATORFACTORY_H
#define ICALCULATORFACTORY_H


#include <string>
#include<memory>

#include "../inc/ICalculator.h"

namespace calculator 
{
    class ICalculatorFactory
    {
        public:

            virtual ~ICalculatorFactory() = default;

            virtual std::unique_ptr<ICalculator> createCalculator(float a, float b, char op) = 0;

            
    };
}
#endif  // ICALCULATORFACTORY_H
