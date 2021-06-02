///////////////////////////////////////////////////////////////////////////////
/**
 * @file  SubtractCalculatorW3.h
 * @date  Wed, 2 June 2021
 * @brief 
 * 
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef SUBTRACTCALCULATORW3_H
#define SUBTRACTCALCULATORW3_H

#include "SimpleExpressionCalculatorW3.h"

namespace calculator 
{
    class SubtractCalculatorW3: public SimpleExpressionCalculatorW3
    {
        public:            
            static const char operation = '-';

            /**
             * @brief disable default constructor, a calculator only makes sense with inputs
             * 
             */
            SubtractCalculatorW3() = delete;

            /**
             * @brief Construct a new Subtract Calculator W 3 object
             * 
             * @param leftTerm 
             * @param rightTerm 
             */
            explicit SubtractCalculatorW3(int leftTerm, int rightTerm);

            /**
             * @brief Get the Result of the equation
             * 
             * @return int 
             */
            int getResult() override;
            
        private:
            /**
             * @brief Get the operation
             * 
             * @return char 
             */
            char getOperation() override;
    };
}
#endif  // SUBTRACTCALCULATORW3_H
