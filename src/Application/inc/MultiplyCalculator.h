/**
 * @file MultiplyCalculator.h
 * @brief Calculator for multiplication '*', multiplies two terms together
 * @version 0.1
 * @date 2021-10-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef MULTIPLYCALCULATOR_H
#define MULTIPLYCALCULATOR_H

#include "../../Application/inc/CalculatorApplication.h"

namespace calculator
{
    class MultiplyCalculator:public CalculatorApplication
    {
        public:
            /**
             * @brief Delete default MultiplyCalculator constructor
             * 
             */
            MultiplyCalculator() = delete;
            
            /**
             * @brief Construct a new Multiply Calculator object
             * 
             * @param a first number
             * @param b second number
             */
            explicit MultiplyCalculator(float a, float b);

            /**
             * @brief Get the Result object
             * 
             * @return float 
             */
            float getResult() override;
    };

}
#endif //MULTIPLYCALCULATOR_H