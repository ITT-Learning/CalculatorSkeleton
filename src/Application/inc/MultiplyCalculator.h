#ifndef MULTIPLYCALCULATOR_H
#define MULTIPLYCALCULATOR_H

//////////////////////////////////////////////////////////////////////////////////
/**
 * @file MultiplyCalculator.h
 * @brief Calculator for multiplication '*', multiplies two terms together
 */
//////////////////////////////////////////////////////////////////////////////////

#include "CalculatorApplication.h"

namespace calculator {

/**
* @brief MultiplyCalculator interface which exposes to other components
*
*/

class MultiplyCalculator : public CalculatorApplication
{
    public:
        /**
         * @brief Delete default MultiplyCalculator constructor
         * 
         */
        MultiplyCalculator() = delete;
        
        /**
         * @brief Construct a new Multiply Calculator object
         * @param firstNumber [in] firstNumber set to firstNumber_
         * @param secondNumber [in] secondNumber set to secondNumber_
         */
        explicit MultiplyCalculator(float firstNumber, float secondNumber);

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

#endif //MULTIPLYCALCULATOR_H
