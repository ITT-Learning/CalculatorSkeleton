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
            Expression expression;
            float answer;
            std::string fullResult;
            void returnResult();
    };
}
#endif  // RESULT_H