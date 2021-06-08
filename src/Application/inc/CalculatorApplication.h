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

namespace calculator 
{
    class CalculatorApplication
    {
        public:
            CalculatorApplication() = delete;

            /**
             * @brief runs calculator prompt in infinite loop
             */
            static void run();

            /**
             * @brief runs calculator prompt in infinite loop with Week 3 implementation
             */
            static void runW3();
    };
}
#endif  // CALCULATORAPPLICATION_H
