#ifndef CALCULATORAPPLICATIONFACTORY_H
#define CALCULATORAPPLICATIONFACTORY_H

////////////////////////////////////////////////////////////////
/**
 * @file CalculatorApplicationFactory.h
 * @brief Factory Pattern class
 */
//////////////////////////////////////////////////////////////

#include <memory>

#include "ICalculatorFactory.h"
namespace calculator {
    
    /**
    * @brief CalculatorFactory interface which exposes to other components
    *
    */
    class CalculatorApplicationFactory : public ICalculatorFactory
    {
        public:
        /**
         * @name ICalculatorFactory methods.
         * @{
         */

        std::unique_ptr<ICalculator> createCalculator(float firstNumber, float secondNumber, char operation) override;

        /**
         * @}
         */

    };

}

#endif  // CALCULATORAPPLICATIONFACTORY_H
