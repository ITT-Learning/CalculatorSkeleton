///////////////////////////////////////////////////////////////////////////////
/**
 * @file  ICalculatorFactory.h
 * @date  Wed, 2 June 2021
 * @brief Abstract factory for calculators
 * 
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef ICALCULATORFACTORY_H
#define ICALCULATORFACTORY_H

#include <memory>
#include <string>

#include "ICalculator.h"

namespace calculator 
{
    class ICalculatorFactory
    {
        public:
            /**
             * @brief Destroy the ICalculatorFactory object
             * 
             */
            virtual ~ICalculatorFactory() = default;

            /**
             * @brief Create a Calculator object
             * 
             * @param mathExpression [in] the left side of the equation
             * @return std::unique_ptr<ICalculator> concrete calculator as determined by mathExpression
             */
            virtual std::unique_ptr<ICalculator> createCalculator(std::string mathExpression) const = 0;
    };
}
#endif  // ICALCULATORFACTORY_H
