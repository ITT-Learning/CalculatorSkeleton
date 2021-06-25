///////////////////////////////////////////////////////////////////////////////
/**
 * @file  SimpleExpressionCalculator.h
 * @date  Wed, 2 June 2021
 * @brief Concrete factory that produces simple expression calculators that are two terms, e.g., '5 + 5'
 * 
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef SIMPLEEXPRESSIONCALCULATOR_H
#define SIMPLEEXPRESSIONCALCULATOR_H

#include <string>

#include "ICalculator.h"

namespace calculator 
{
    class SimpleExpressionCalculator : public ICalculator
    {
        public:
            /**
             * @brief The left side of the equation [leftTerm] [operation] [rightTerm],  e.g. '5 + 5'
             * 
             * @return std::string 
             */
            std::string getExpression() const final;

            /**
             * @brief The full equation represented as a string [leftTerm] [operation] [rightTerm] = [result]
             * 
             * @return std::string 
             */
            std::string toString() const final;
        protected:
            int leftTerm_;
            int rightTerm_;
            /**
             * @brief Helper function to get the operation to compose the expression
             * 
             * @return char 
             */
            virtual char getOperation() const = 0;
    };
}
#endif  // SIMPLEEXPRESSIONCALCULATOR_H
