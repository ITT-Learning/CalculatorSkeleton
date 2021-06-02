///////////////////////////////////////////////////////////////////////////////
/**
 * @file  AddCalculatorW3.h
 * @date  Wed, 2 June 2021
 * @brief 
 * 
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef ADDCALCULATORW3_H
#define ADDCALCULATORW3_H

#include "SimpleExpressionCalculatorW3.h"

namespace calculator 
{
    class AddCalculatorW3: public SimpleExpressionCalculatorW3
    {
        public:            
            static const char operation = '+';

            /**
             * @brief disable default constructor, a calculator only makes sense with inputs
             * 
             */
            AddCalculatorW3() = delete;

            /**
             * @brief Construct a new Add Calculator W 3 object
             * 
             * @param leftTerm 
             * @param rightTerm 
             */
            explicit AddCalculatorW3(int leftTerm, int rightTerm);
            /**
             * @brief Get the result or right side of the equation
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
#endif  // ADDCALCULATORW3_H
