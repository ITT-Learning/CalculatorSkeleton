///////////////////////////////////////////////////////////////////////////////
/**
 * @file  CalculatorStrings.h
 * @date  Tue, 1 June 2021
 * @brief 
 * 
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef CALCULATORSTRINGS_H
#define CALCULATORSTRINGS_H

#include <string>
namespace calculator
{
    struct CalculatorStrings
    {
        /**
         * @brief prompt passed to user before retrieving input from them
         * 
         */
        static const std::string MAIN_PROMPT; 
        
        /**
         * @brief response given to user if input is invalid
         * 
         */
        static const std::string INVALID_INPUT;
    };
} // namespace calculator


#endif // CALCULATORSTRINGS_H