/**
 * @file SubtractCalculator.h
 * @brief Calculator for subtraction '-', subtracts two terms together
 * @version 0.1
 * @date 2021-10-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef SUBTRACTCALCULATOR_H
#define SUBTRACTCALCULATOR_H

#include "../../Application/inc/CalculatorApplication.h"

namespace calculator
{
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
             * 
             * @param a first number
             * @param b second number
             */
            explicit SubtractCalculator(float a, float b);

            /**
             * @brief Get the Result object
             * 
             * @return float 
             */
            float getResult() override;
    };
    

}
#endif //SUBTRACTCALCULATOR_H