///////////////////////////////////////////////////////////////////////////////
/**
 * @file  SimpleExpressionCalculatorFactory.h
 * @date  Wed, 2 June 2021
 * @brief Concrete factory for simple expression calculators
 * 
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef SIMPLEEXPRESSIONCALCULATORFACTORY_H
#define SIMPLEEXPRESSIONCALCULATORFACTORY_H

#include <string>
#include <memory>

#include "ICalculator.h"
#include "ICalculatorFactory.h"

namespace calculator 
{
    class SimpleExpressionCalculatorFactory : ICalculatorFactory
    {
        public:
            /**
             * @brief Create a Simple Expression Calculator Object
             * 
             * @param mathExpression should be in the form of [leftTerm] [operation] [rightTerm], e.g. '5 + 5'
             * @return std::unique_ptr<ICalculator> - [Add/Subtract/Divide/Multiply]Calculator
             */
            std::unique_ptr<ICalculator> createCalculator(std::string mathExpression) const override;
    };
}
#endif  // SIMPLEEXPRESSIONCALCULATORFACTORY_H
