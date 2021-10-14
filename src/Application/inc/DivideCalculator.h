/**
 * @file DivideCalculator.h
 * @brief Calculator for division '/', divides two terms together
 * @version 0.1
 * @date 2021-10-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef DIVIDECALCULATOR_H
#define DIVIDECALCULATOR_H

#include "../../Application/inc/CalculatorApplication.h"

namespace calculator
{
    class DivideCalculator:public CalculatorApplication
    {
        public:
            /**
             * @brief Delete default DivideCalculator Constructor
             * 
             */
            DivideCalculator() = delete;

            /**
             * @brief Construct a new Divide Calculator object
             * 
             * @param a first number
             * @param b second number
             */
            explicit DivideCalculator(float a, float b);

            /**
             * @brief Get the Result object
             * 
             * @return float 
             */
            float getResult() override;
    };

}
#endif //DIVIDECALCULATOR_H