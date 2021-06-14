///////////////////////////////////////////////////////////////////////////////
/**
 * @file  ICalculatorTemplateFactory.h
 * @date  Wed, 2 June 2021
 * @brief Abstract factory for templated calculators
 * 
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef ICALCULATORTEMPLATEFACTORY_H
#define ICALCULATORTEMPLATEFACTORY_H

#include <memory>
#include <string>

#include "ICalculatorTemplate.h"

namespace calculator 
{
    template <typename T>
    class ICalculatorTemplateFactory
    {
        public:
            /**
             * @brief Destroy the ICalculatorTemplateFactory object
             * 
             */
            virtual ~ICalculatorTemplateFactory() = default;

            /**
             * @brief Create a Calculator Template object
             * 
             * @param mathExpression [in] the left side of the equation
             * @return std::unique_ptr<ICalculator<T>> concrete calculator as determined by mathExpression
             */
            virtual std::unique_ptr<ICalculatorTemplate<T>> createCalculator(std::string mathExpression) const = 0;
    };
}
#endif  // ICALCULATORTEMPLATEFACTORY_H
