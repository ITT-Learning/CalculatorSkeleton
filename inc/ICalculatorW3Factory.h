///////////////////////////////////////////////////////////////////////////////
/**
 * @file  ICalculatorW3Factory.h
 * @date  Wed, 2 June 2021
 * @brief 
 * 
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef ICALCULATORW3FACTORY_H
#define ICALCULATORW3FACTORY_H

#include <string>
#include <memory>

#include "ICalculatorW3.h"

namespace calculator 
{
    class ICalculatorW3Factory
    {
        public:
            /**
             * @brief Destroy the ICalculatorW3Factory object
             * 
             */
            virtual ~ICalculatorW3Factory() {}
            /**
             * @brief Create a Calculator object
             * 
             * @param mathExpression [in] the left side of the equation
             * @return std::unique_ptr<ICalculatorW3>
             */
            virtual std::unique_ptr<ICalculatorW3> createCalculator(std::string mathExpression) = 0;
    };
}
#endif  // ICALCULATORW3FACTORY_H
