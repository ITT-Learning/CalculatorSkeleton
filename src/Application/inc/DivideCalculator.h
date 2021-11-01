#ifndef DIVIDECALCULATOR_H
#define DIVIDECALCULATOR_H

///////////////////////////////////////////////////////////////////
/**
 * @file DivideCalculator.h
 * @brief Calculator for division '/', divides two terms together
 */
///////////////////////////////////////////////////////////////////

#include "CalculatorApplication.h"

namespace calculator {

<<<<<<< HEAD
    /**
    * @brief DivideCalculator interface which exposes to other components
    */
    class DivideCalculator : public CalculatorApplication
    {
        public:
            /**
             * @brief Delete default DivideCalculator Constructor
             * 
             */
            DivideCalculator() = delete;

            /**
             * @brief Construct a new Divide Calculator object
             * @param firstNumber [in] firstNumber set to secondNumber_
             * @param secondNumber [in] secondNumber set to secondNumber_
             */
            explicit DivideCalculator(float firstNumber, float secondNumber);

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
* @brief DivideCalculator interface which exposes to other components
*/

class DivideCalculator : public CalculatorApplication
{
    public:
        /**
         * @brief Delete default DivideCalculator Constructor
         * 
         */
        DivideCalculator() = delete;

        /**
         * @brief Construct a new Divide Calculator object
         * @param firstNumber [in] firstNumber set to secondNumber_
         * @param secondNumber [in] secondNumber set to secondNumber_
         */
        explicit DivideCalculator(float firstNumber, float secondNumber);

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

#endif //DIVIDECALCULATOR_H
