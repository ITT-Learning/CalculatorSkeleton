#ifndef ICALCULATOR_H
#define ICALCULATOR_H

/////////////////////////////////////////////////////
/**
 * @file ICalculator.h
 * @brief Interface used by main
 */
/////////////////////////////////////////////////////

#include <string>

namespace calculator {
class ICalculator 
{
    public:
        /**
         * @brief Destroy the ICalculator object
         * 
         */
        ~ICalculator() = default;

        /**
         * @brief Get the Result object 
         * 
         * @return float defined by calculation defined in child classes 
         */
        virtual float getResult() = 0;

        /**
         * @brief Convert to string function (output)
         * 
         * @return convert calculator output and functionality std::toString
         */
        virtual std::string toString() = 0;
};
    
} // namespace calculator

#endif //ICALCULATOR_H
