///////////////////////////////////////////////////////////////////////////////
/**
 * @file  MultiplyCalculatorW3.h
 * @date  Wed, 2 June 2021
 * @brief 
 * 
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef MULTIPLYCALCULATORW3_H
#define MULTIPLYCALCULATORW3_H

#include "SimpleExpressionCalculatorW3.h"

namespace calculator 
{
    class MultiplyCalculatorW3: public SimpleExpressionCalculatorW3
    {
        public:            
            static const char operation = '*';

            /**
             * @brief disable default constructor, a calculator only makes sense with inputs
             * 
             */
            MultiplyCalculatorW3() = delete;

            /**
             * @brief Construct a new Subtract Calculator W 3 object
             * 
             * @param leftTerm 
             * @param rightTerm 
             */
            explicit MultiplyCalculatorW3(int leftTerm, int rightTerm);
            /**
             * @brief Get the result or the right side of the equation
             * 
             * @return int 
             */
            int getResult() override;
        private:
            /**
             * @brief Get the Operation object
             * 
             * @return char 
             */
            char getOperation() override;
    };
}
#endif  // MULTIPLYCALCULATORW3_H
