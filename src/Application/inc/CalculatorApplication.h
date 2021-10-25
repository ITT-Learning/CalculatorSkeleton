///////////////////////////////////////////////////////////////////////////////
/**
 * @file  CalculatorApplication.h
 * @date  Fri, 16 April 2021
 * 
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef CALCULATORAPPLICATION_H
#define CALCULATORAPPLICATION_H

#include "CalculatorStrings.h"
#include "ICalculator.h"
#include <iostream>
#include <limits>
#include <string>



<<<<<<< HEAD
namespace calculator {
    /**
     * @brief This is the Class containing the functions and variables used in week 1
     */
    class CalculatorApplication
=======
namespace calculator
{
    class CalculatorApplication : public ICalculator 
>>>>>>> 3c21844efb27366021dcf5946e252daa836ce015
    {
        public:
            /**
             * @brief Construct a new Calculator object
             * 
             */
            CalculatorApplication() = default;
            
            /**
             * @brief This is the main function run in main.cpp
             * @param a first number float 
             * @param b second number float
             * @param op operator char
             */
            CalculatorApplication(float a, float);

            static int calculate(float a, float b, char op);
            
            /**
             * @brief Get the Result object. Pure virtual function defined in child classes
             * 
             * @return float 
             */
            virtual float getResult() = 0;
            
            std::string toString() override;

            /**
             * @brief Checks if the inputted value is within scope
             * 
             * @param a 
             * @return true 
             * @return false 
             */
            static bool limitCheck(float a);

        protected:
            float firstNumber_;
            float secondNumber_;
            char op_; 


    };
} // namespace calculator
#endif  // CALCULATORAPPLICATION_H