///////////////////////////////////////////////////////////////////////////////
/**
 * @file  DivideCalculatorW3.h
 * @date  Wed, 2 June 2021
 * @brief 
 * 
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef DIVIDECALCULATORW3_H
#define DIVIDECALCULATORW3_H

#include "SimpleExpressionCalculatorW3.h"

namespace calculator 
{
    class DivideCalculatorW3: public SimpleExpressionCalculatorW3
    {
        public:            
            static const char operation = '/';

            /**
             * @brief disable default constructor, a calculator only makes sense with inputs
             * 
             */
            DivideCalculatorW3() = delete;

            /**
             * @brief Construct a new Divide Calculator
             * @note If the rightTerm is 0 then a message is set to std error and the result will be -1
             * 
             * @param leftTerm 
             * @param rightTerm 
             */
            explicit DivideCalculatorW3(int leftTerm, int rightTerm);
            int getResult() override;
        private:
            char getOperation() override;
    };
}
#endif  // DIVIDECALCULATORW3_H
