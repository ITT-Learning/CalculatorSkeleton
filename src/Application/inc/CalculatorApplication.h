///////////////////////////////////////////////////////////////////////////////
/**
 * @file  CalculatorApplication.h
 * @date  Wed, 9 June 2021
 * @brief Static class that runs a calculator implementation
 * 
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef CALCULATORAPPLICATION_H
#define CALCULATORAPPLICATION_H

#include <functional>

namespace calculator
{
    class CalculatorApplication
    {
        public:
            CalculatorApplication() = delete;

            /**
            * @brief For testing and playing around with concepts
            */
            static void playground();

            /**
             * @brief helper function to call a runWx that I want
             */
            static void run();

            /**
             * @brief runs calculator prompt in infinite loop with Week 3 implementation
             */
            static void runW3();

            /**
             * @brief runs calculator prompt in infinite loop
             */
            static void runW4();

            /**
             * @brief runs calculator prompt in infinite loop
             */
            static void runW5();

            /**
             * @brief Infinite loop for user input. Will break loop if user 'exit' 'e' 'quit' 'q'.
             */
            static void inputLoop(const std::string& prompt, const std::function<void(const std::string&)>& function);
    };
}
#endif  // CALCULATORAPPLICATION_H
