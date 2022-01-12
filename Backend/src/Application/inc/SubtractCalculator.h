#ifndef SUBTRACTCALCULATOR_H
#define SUBTRACTCALCULATOR_H

/////////////////////////////////////////////////////////////////////
/**
 * @file SubtractCalculator.h
 * @brief Calculator for subtraction '-', subtracts two terms together
 */
/////////////////////////////////////////////////////////////////////

#include "ICalculator.h"

namespace calculator {

/**
 * @brief SubtractCalculator interface which exposes to other components
 *
 */

class SubtractCalculator : public ICalculator
{
    public:
        /**
         * @brief Delete default SubtractCalculator constructor
         * 
         */
        SubtractCalculator() = delete;
        
        /**
         * @brief Construct a new Subtract Calculator object 
         * @param [in] firstNumber firstNumber set to firstNumber_
         * @param [in] secondNumber secondNumber set to secondNumber_
         */
        explicit SubtractCalculator(float firstNumber, float secondNumber);

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

#endif //SUBTRACTCALCULATOR_H
