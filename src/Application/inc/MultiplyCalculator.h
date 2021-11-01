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

<<<<<<< HEAD
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
=======
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
>>>>>>> 2085be165f0cff9b9b8d290c375838c98aaaabb9

} // namespace calculator

#endif //MULTIPLYCALCULATOR_H
