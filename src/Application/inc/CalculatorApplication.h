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


namespace calculator {
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
             * @param number1 [in] This is the first float passed into
             * @param number2 [in]This is the second float passed into 
             * @return both values added together
             */
            float add(float number1, float number2);

            /**
             * @brief This is the function multiplying two floats using the '*' character
             * @param number1 [in] This is the first float passed into
             * @param number2 [in] This is the second float passed into
             * @return both values added together
             */
            float multiply(float number1, float number2);
            /**
             * @brief This is the function dividing two floats using the '/' character
             * @param number1 [in] This is the first float passed into
             * @param number2 [in] This is the second float passed into
             * @return both values multiplied together
             */
            float divide(float number1, float number2);
            /**
             * @brief This is the function subtract two floats using the '-' character
             * @param number1 [in] This is the first float passed into
             * @param number2 [in] This is the second float passed into
             * @return both values divided together
             */
            
            float subtract(float number1, float number2);
            /**
             * @brief This is the function taking the modulus two floats using the '%' character
             * @param number1 [in] This is the first float passed into
             * @param number2 [in] This is the second float passed into
             * @return both values subtracted together
             */
            int modulus(float number1, float number2);
    };
} // namespace calculator
#endif  // CALCULATORAPPLICATION_H