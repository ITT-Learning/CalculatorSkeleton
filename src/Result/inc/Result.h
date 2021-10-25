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

namespace calculator
{
    class Result : public IResult
    {
        public:
            Result(std::string originalEquation, float answer, std::string fullResult) :
            originalEquation_(originalEquation), answer_(answer), fullResult_(fullResult){}

        /***
         * @brief get the full result string
         * @return std::string the fullResult
         */

            std::string getFullResult() const override;

        private:
            float       answer_;
            std::string originalEquation_;
            std::string fullResult_;
    };
}
#endif  // RESULT_H
