#ifndef ADDCALCULATOR_H
#define ADDCALCULATOR_H

///////////////////////////////////////////////////////////////////
/**
 * @file AddCalculator.h
 * @brief Calculator for addition '+', adds two terms together
 */
///////////////////////////////////////////////////////////////////

#include "CalculatorApplication.h"

namespace calculator {

/**
* @brief AddCalculator interface which exposes to other components
*
*/

<<<<<<< HEAD
namespace calculator {

    /**
    * @brief AddCalculator interface which exposes to other components
    *
    */
    class AddCalculator : public CalculatorApplication
    {
        public:
            /**
             * @brief Delete default constructor
             */
            AddCalculator() = delete;

            /**
             * @brief Construct a new Add Calculator object
             * @param firstNumber [in] first number set to firstNumber_
             * @param secondNumber [in] Second number set to secondNumber_
             */
            explicit AddCalculator(float firstNumber, float secondNumber);

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
class AddCalculator : public CalculatorApplication
{
    public:
        /**
         * @brief Delete default constructor
         */
        AddCalculator() = delete;

        /**
         * @brief Construct a new Add Calculator object
         * @param firstNumber [in] first number set to firstNumber_
         * @param secondNumber [in] Second number set to secondNumber_
         */
        explicit AddCalculator(float firstNumber, float secondNumber);

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
} //namespace calculator

#endif //ADDCALCULATOR_H
