///////////////////////////////////////////////////////////////////////////////
/**
 * @file  CustomCalculatorFactory.h
 * @date  Wed, 2 June 2021
 * @brief Concrete factory for custom calculators
 *        template class see CustomCalculatorFactory.cpp for defined types
 * 
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef CUSTOMCALCULATORFACTORY_H
#define CUSTOMCALCULATORFACTORY_H

#include <string>
#include <functional>
#include <vector>

#include "ICalculatorTemplate.h"
#include "ICalculatorTemplateFactory.h"

namespace calculator
{
    template <class T>
    class CustomCalculatorFactory : ICalculatorTemplateFactory<T>
    {
        public:
            /**
             * @brief no default implementation, must be constructed with function and expression format
             */
            CustomCalculatorFactory() = delete;

            /**
             * @brief Construct a Custom Calculator Factory that will create custom calculators with custom functions
             *        int, double, and float is enabled
             *
             * @param func function to solve with your terms example with lambda:
             *                  [](std::vector<int> n){return (n[0] + n[1]) * n[2];}
             * @param expressionFormat python like expression format with bracket pairs as place holders
             *                              e.g. "({} + {}) * {}"
             */
            CustomCalculatorFactory(std::function<T(std::vector<T>)> func, std::string expressionFormat);
            /**
             * @brief Create a Custom Calculator Object
             *
             * @param mathExpression ignores any non-numbers split by spaces
             * @return std::unique_ptr<ICalculatorTemplate<T>> - Custom Calculator
             *         will return nullptr if argCount does not match
             */
            std::unique_ptr<ICalculatorTemplate<T>> createCalculator(std::string mathExpression) const final;
        private:
            int argCount_;
            std::function<T(std::vector<T>)> function_;
            std::string expressionFormat_;
            mutable int count_ = 0;

            /**
             * @brief finds the number of available slots to put terms in the expressionFormat_ string
             * @warning needs improvement to protect against
             * @return number of available slots in expressionFormat_
             */
            int findArgCount() const;
    };
}
#endif  // CUSTOMCALCULATORFACTORY_H
