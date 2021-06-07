///////////////////////////////////////////////////////////////////////////////
/**
 * @file  SimpleExpressionCalculatorW3.h
 * @date  Wed, 2 June 2021
 * @brief Concrete factory that produces simple expression calcualtors that are two terms, e.g., '5 + 5'
 * 
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef SIMPLEEXPRESSIONCALCULATORW3_H
#define SIMPLEEXPRESSIONCALCULATORW3_H

#include <string>

#include "ICalculatorW3.h"

namespace calculator 
{
    class SimpleExpressionCalculatorW3 : public ICalculatorW3
    {
        public:
            /**
             * @brief The left side of the equation [leftTerm] [operation] [rightTerm],  e.g. '5 + 5'
             * 
             * @return std::string 
             */
            std::string getExpression() override final;
            /**
             * @brief The solved right side of the equation
             * 
             * @return int 
             */
            virtual int getResult() = 0;
            /**
             * @brief The full equation represented as a string [leftTerm] [operation] [rightTerm] = [result]
             * 
             * @return std::string 
             */
            std::string toString() override final;
        protected:
            int leftTerm_;
            int rightTerm_;
            /**
             * @brief Helper function to get the operation to compose the expression
             * 
             * @return char 
             */
            virtual char getOperation() = 0;
    };
}
#endif  // SIMPLEEXPRESSIONCALCULATORW3_H
