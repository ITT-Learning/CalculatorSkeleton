///////////////////////////////////////////////////////////////////////////////
/**
 * @file  CalculatorApplication.h
 * @date  Fri, 16 April 2021
 * @brief These are the included header files as well as the programs function declarations
 * 
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef CALCULATORAPPLICATION_H
#define CALCULATORAPPLICATION_H

#include <string>
#include "../../Interface/inc/ICalculator.h"
#include "CalculatorStrings.h"
#include <limits>


namespace calculator
{
    /**
     * @brief This is the Class containing the functions and variables used in week 1
     */
    class CalculatorApplication : public ICalculator 
    {
        public:
            /**
             * @brief Construct a new Calculator object
             * 
             */
            CalculatorApplication() = default;
            /**
             * @brief Destroy the Calculator object
             * 
             */
            ~CalculatorApplication() = default;
            
            /**
             * @brief This is the main function run in main.cpp
             * 
             */
            static int calculate(float a, float b, char op);
            
            /**
             * @brief Get the Result object. Pure virtual function defined in child classes
             * 
             * @return float 
             */
            virtual float getResult() = 0;
            
            /**
             * @brief Convert to string function
             * 
             * @return std::string 
             */
            std::string toString() override;

            static bool limitCheck(float a);



        protected:
            float first_Number;
            float second_Number;
            char op; 


    };
}
#endif  // CALCULATORAPPLICATION_H