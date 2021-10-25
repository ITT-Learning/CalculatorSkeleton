#ifndef SUBTRACTCALCULATOR_H
#define SUBTRACTCALCULATOR_H

/////////////////////////////////////////////////////////////////////
/**
 * @file SubtractCalculator.h
 * @brief Calculator for subtraction '-', subtracts two terms together
 */
/////////////////////////////////////////////////////////////////////

#include "CalculatorApplication.h"

namespace calculator {

    /**
     * @brief SubtractCalculator interface which exposes to other components
     *
     */
    class SubtractCalculator : public CalculatorApplication
    {
        public:
            /**
             * @brief Delete default SubtractCalculator constructor
             * 
             */
            SubtractCalculator() = delete;
            
            /**
             * @brief Construct a new Subtract Calculator object 
             * @param firstNumber [in] firstNumber set to firstNumber_
             * @param secondNumber [in] secondNumber set to secondNumber_
             */
            explicit SubtractCalculator(float firstNumber, float secondNumber);

            /**
             * @name CalculatorApplication methods.
             * @{
             */

            float getResult() override;

            /**
             * @}
             */

    };

} // namespace calculator

#endif //SUBTRACTCALCULATOR_H
