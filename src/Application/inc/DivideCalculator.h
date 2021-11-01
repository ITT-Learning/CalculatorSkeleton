#ifndef DIVIDECALCULATOR_H
#define DIVIDECALCULATOR_H

///////////////////////////////////////////////////////////////////
/**
 * @file DivideCalculator.h
 * @brief Calculator for division '/', divides two terms together
 */
///////////////////////////////////////////////////////////////////

#include "ICalculator.h"

namespace calculator {

/**
* @brief DivideCalculator interface which exposes to other components
*/

class DivideCalculator : public ICalculator
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

} // namespace calculator

#endif //DIVIDECALCULATOR_H
