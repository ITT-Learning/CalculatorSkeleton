#ifndef IRESULT_H
#define IRESULT_H

///////////////////////////////////////////////////////////////////////////////
/**
 * @file  IResult.h
 * @brief Interface for result objects
 */
///////////////////////////////////////////////////////////////////////////////

#include <string>

namespace calculator {

/**
* @brief IResult interface which exposes to other components
*/

class IResult
{
    public:
        /**
         * @brief Destroy the IResult object
         */
        virtual ~IResult() = default;

        /**
         * @brief virtual function that will be defined by classes inheriting from the Interface
         */
        virtual std::string getFullResult() const = 0;
};

} //namespace calculator

#endif  // ICALCULATOR_H
