///////////////////////////////////////////////////////////////////////////////
/**
 * @file  SimpleExpressionCalculatorW3Factory.h
 * @date  Wed, 2 June 2021
 * @brief Concrete factory for simple expression calculators
 * 
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef SIMPLEEXPRESSIONCALCULATORW3FACTORY_H
#define SIMPLEEXPRESSIONCALCULATORW3FACTORY_H

#include <string>
#include <memory>

#include "ICalculatorW3.h"
#include "ICalculatorW3Factory.h"

namespace calculator 
{
    class SimpleExpressionCalculatorW3Factory : ICalculatorW3Factory
    {
        public:
            /**
             * @brief Create a Simple Expression Calculator Object
             * 
             * @param mathExpression should be in the form of [leftTerm] [operation] [rightTerm], e.g. '5 + 5'
             * @return std::unique_ptr<ICalculatorW3> - [Add/Subtract/Divide/Multiply]Calculator
             */
            std::unique_ptr<ICalculatorW3> createCalculator(std::string mathExpression) override;
    };
}
#endif  // SIMPLEEXPRESSIONCALCULATORW3FACTORY_H
