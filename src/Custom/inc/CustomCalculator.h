///////////////////////////////////////////////////////////////////////////////
/**
 * @file  CustomCalculator.h
 * @date  Wed, 2 June 2021
 * @brief Calculator capable of extreme customization
 *        Is a template class - check end of CustomCalculator.cpp to see which classes are defined
 * @note https://stackoverflow.com/questions/8752837/undefined-reference-to-template-class-constructor
 * 
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef CUSTOMTEMPLATECALCULATOR_H
#define CUSTOMTEMPLATECALCULATOR_H

#include <functional>
#include <sstream>
#include <vector>

#include "fmt/core.h"

#include "CalculatorStrings.h"
#include "ICalculatorTemplate.h"

namespace calculator 
{
    template <class T>
    class CustomCalculator : public ICalculatorTemplate<T>
    {
        public:
            /**
             * @brief Do not allow default construction
             */
            CustomCalculator() = delete;

            /**
             * @brief Make Custom Calculator Object
             *
             * @param terms List of terms to be manipulated, terms will be used in function and in constructing the string
             * @param func [in] function to solve with your terms example with lambda:
             *                  [](std::vector<int> n){return (n[0] + n[1]) * n[2];}
             * @param expressionFormat [in] python like expression format with bracket pairs as place holders
             *                              e.g. "({} + {}) * {}"
             */
            explicit CustomCalculator(std::vector<T> terms, std::function<T(std::vector<T>)> func, std::string expressionFormat);

            /**
             * @brief The left side of the equation determined by the expressionFormat and the terms
             *
             * @return std::string formatted expression
             */
            std::string getExpression() const final;

            /**
             * @brief the results of plugging the terms into the function
             *
             * @return T
             */
            T getResult() const final;

            /**
             * @brief The full equation represented as a string i.e., <expression> = <result>
             *
             * @return std::string "<expression> = <result>"
             */
            std::string toString() const final;

        private:
            int                              argCount_ = 0;
            std::string                      expression_;
            std::function<T(std::vector<T>)> function_;
            std::vector<T>                   terms_;

            /**
             * @brief finds the number of available slots to put terms in the expression_ string
             * @warning needs improvement to protect against misformed expressions
             * @return number of available slots in expressionFormat_
             */
            int findArgCount() const;
    };
}
#endif  // CUSTOMTEMPLATECALCULATOR_H
