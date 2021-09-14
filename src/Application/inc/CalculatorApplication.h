///////////////////////////////////////////////////////////////////////////////
/**
 * @file  Calculator.h
 * @date  Fri, 16 April 2021
 * @brief These are the included header files as well as the programs function declarations
 * 
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef CALCULATORAPPLICATION_H
#define CALCULATORAPPLICATION_H


namespace calculator
{
    /**
     * @brief This is the Class containing the functions and variables used in week 1
     */
    class CalculatorApplication
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
            void calculate();
            /**
             * @brief This is the function adding two floats using the '+' character
             * @param number1 This is the first float passed into
             * @param number2 This is the second float passed into 
             * @param op This is the operator character and will add both floats
             */
            float add(float number1, float number2);
            /**
             * @brief This is the function multiplying two floats using the '*' character
             * @param number1 This is the first float passed into
             * @param number2 This is the second float passed into
             * @param op This is the operator character and will multiply both floats
             */
            float multiply(float number1, float number2);
            /**
             * @brief This is the function dividing two floats using the '/' character
             * @param number1 This is the first float passed into
             * @param number2 This is the second float passed into
             * @param op This is the operator character and will divide both floats
             */
            float divide(float number1, float number2);
            /**
             * @brief This is the function subtract two floats using the '-' character
             * @param number1 This is the first float passed into
             * @param number2 This is the second float passed into
             * @param op This is the operator character and will subtract both floats
             */
            
            float subtract(float number1, float number2);
            /**
             * @brief This is the function taking the modulus two floats using the '%' character
             * @param number1 This is the first float passed into
             * @param number2 This is the second float passed into
             * @param op This is the operator character and will return the modulus of both floats
             */
            int modulus(float number1, float number2);
    };
}
#endif  // CALCULATOR_H