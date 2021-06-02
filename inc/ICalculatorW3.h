///////////////////////////////////////////////////////////////////////////////
/**
 * @file  ICalculatorW3.h
 * @date  Wed, 2 June 2021
 * @brief 
 * 
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef ICALCULATORW3_H
#define ICALCULATORW3_H

#include <string>

namespace calculator 
{
    class ICalculatorW3
    {
        public:
            /**
             * @brief Destroy the ICalculatorW3 object
             * 
             */
            virtual ~ICalculatorW3() {}
            /**
             * @brief The left side of the equation
             * 
             * @return std::string 
             */
            virtual std::string getExpression() = 0;
            /**
             * @brief the solved, right side, of the equation equation
             * 
             * @return int 
             */
            virtual int getResult() = 0;
            /**
             * @brief The full equation representation
             * 
             * @return std::string 
             */
            virtual std::string toString() = 0;
    };
}
#endif  // ICALCULATORW3_H
