////////////////////////////////////////////////////////////////////////////////
/**
* @file Result.h
* @brief Result Object function declarations.
*/
////////////////////////////////////////////////////////////////////////////////
#include "Parser.h"
#include <string>

#ifndef RESULT_H
#define RESULT_H

namespace calculator
{
    class Result
    {
        public:
            Result(Expression expression, float answer, std::string fullResult) : expression_(expression), answer_(answer), fullResult_(fullResult){}

            /**
             * @returns the full result string
            */
            std::string getFullResult();
        private:
            Expression expression_;
            float answer_;
            std::string fullResult_;
    };
}
#endif  // RESULT_H