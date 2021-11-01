#ifndef ICALCULATORFACTORY_H
#define ICALCULATORFACTORY_H

///////////////////////////////////////////////////////////////////
/**
 * @file ICalculatorFactory.h
 * @brief Factory Interface used by main
 */
///////////////////////////////////////////////////////////////////

#include<memory>

#include "ICalculator.h"

namespace calculator {

class ICalculatorFactory
{
    public:
        /**
         * @brief Destroy the ICalculatorFactory object
         * 
         */
        virtual ~ICalculatorFactory() = default;

        /**
         * @brief virtual function defined in CalculatorApplicationFactory.cpp
         * 
         * @param firstNumber [in] firstNumber passed to specific calculator based on operation
         * @param secondNumber [in] secondNumber passed to specific calculator based on operation
         * @param operation [in] operation passed to determine which calculator to send firstNumber and secondNumber
         * @return std::unique_ptr<ICalculator> which is pointer object to determined specified calculator
         */
        virtual std::unique_ptr<ICalculator> createCalculator(float firstNumber, float secondNumber, char operation) = 0;
};

} // namespace calculator

#endif  // ICALCULATORFACTORY_H
