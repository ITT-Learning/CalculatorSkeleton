/**
 * @file ICalculator.h
 * @brief Interface used by main
 * @version 0.1
 * @date 2021-10-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef ICALCULATOR_H
#define ICALCULATOR_H

#include <string>
#include <iostream>

namespace calculator
{
    class ICalculator 
    {
        public:
            
            ~ICalculator() = default;

            virtual float getResult() = 0;

            virtual std::string toString() = 0;
    };
    

}
#endif //ICALCULATOR_H