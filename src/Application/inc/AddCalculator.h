#ifndef ADDCALCULATOR_H
#define ADDCALCULATOR_H

///////////////////////////////////////////////////////////////////
/**
 * @file AddCalculator.h
 * @brief Calculator for addition '+', adds two terms together
 */
///////////////////////////////////////////////////////////////////

#include "ICalculator.h"

namespace calculator {

/**
* @brief AddCalculator interface which exposes to other components
*
*/

class AddCalculator : public ICalculator
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
         * @name ICalculator methods.
         * @{
         */

        float getResult() const override;

        std::string const toString() override;

        /**
         * @}
         */ 

        private:   
            float firstNumber_;
            float secondNumber_;
            char  operator_;
        
};

} //namespace calculator

#endif //ADDCALCULATOR_H
