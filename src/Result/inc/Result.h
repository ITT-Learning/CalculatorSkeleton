////////////////////////////////////////////////////////////////////////////////
/**
* @file Result.h
* @brief Result Object function declarations.
*/
////////////////////////////////////////////////////////////////////////////////
#include <string>

#include "Parser.h"

#ifndef RESULT_H
#define RESULT_H

namespace calculator
{
    class Result
    {
        public:
            Result(Expression expression, float answer, std::string fullResult) : expression_(expression), answer_(answer), fullResult_(fullResult){}

        /***
         * @brief get the full result string
         *
         * @return std::string the fullResult
         */

            std::string getFullResult();

        private:
            float       answer_;
            Expression  expression_;
            std::string fullResult_;
    };
}
#endif  // RESULT_H