#ifndef RESULT_H
#define RESULT_H

////////////////////////////////////////////////////////////////////////////////
/**
* @file Result.h
* @brief Result Object function declarations.
*/
////////////////////////////////////////////////////////////////////////////////

#include <string>

#include "Parser.h"
#include "IResult.h"

namespace calculator {

    /**
    * @brief Result interface which exposes to other components
    */

    class Result : public IResult
    {
        public:
            /***
             * Constructor for Result
             */
            Result(std::string originalEquation, float answer, std::string fullResult) :
            originalEquation_(originalEquation), answer_(answer), fullResult_(fullResult){}

            /**
             * @name IResult methods.
             * @{
             */

            std::string getFullResult() const override;

            /**
             * @}
             */


        private:
            float       answer_;
            std::string originalEquation_;
            std::string fullResult_;
    };

} //namespace calculator

#endif  // RESULT_H
