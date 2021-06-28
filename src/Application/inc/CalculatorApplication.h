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
    enum class Options : char
    {
        FIRST  = '1',
        SECOND = '2',
        THIRD  = '3',
        FOURTH = '4',
        UP     = 'w',
        DOWN   = 's'
    };

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
             * @brief runs calculator prompt in infinite loop for week 4
             */
            static void runW4();

            /**
             * @brief runs calculator prompt in infinite loop for week 5
             */
            static void runW5();

            /**
             * @brief runs calculator prompt in infinite loop for week 6
             */
            static void runW6();

        private:
            /**
             * @brief Move up and down history
             */
            static void history();

            /**
             * @brief Infinite loop for user input. Will break loop if user 'exit' 'e' 'quit' 'q'.
             * @param prompt [in] Message to display to the user every loop
             * @param function [in] (lambda) of what to do with the user input
             */
            static void inputLoop(const std::string& prompt, const std::function<void(const std::string&)>& function);

            /**
             * @brief does a string match one of the exit strings?
             * @param input [in] user input
             * @return bool - true if match exit, false otherwise
             */
            static bool isExitString(const std::string& input);
    };
}
#endif  // CALCULATORAPPLICATION_H
