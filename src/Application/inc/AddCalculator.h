/**
 * @file AddCalculator.h
 * @brief Calculator for addition '+', adds two terms together
 * @version 0.1
 * @date 2021-10-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef ADDCALCULATOR_H
#define ADDCALCULATOR_H

#include "CalculatorApplication.h"


namespace calculator
{
    class AddCalculator : public CalculatorApplication
    {
        public:
            /**
             * @brief Delete default constructor
             * 
             */
            AddCalculator() = delete;

            /**
             * @brief Construct a new Add Calculator object
             * 
             * @param a first number
             * @param b Second number
             */
            explicit AddCalculator(float a, float b);

            /**
             * @brief Get the Result object
             * 
             * @return float 
             */
            float getResult() override;
    };
    

}
#endif //ADDCALCULATOR_H