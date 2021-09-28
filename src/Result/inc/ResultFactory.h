////////////////////////////////////////////////////////////////////////////////
/**
* @file ResultFactory.h
* @brief Result Object function declarations.
*/
////////////////////////////////////////////////////////////////////////////////

//this is going to create and return the result object
#ifndef RESULTFACTORY_H
#define RESULTFACTORY_H

#include "Result.h"
#include "ResultFactory.h"

namespace calculator
{
    class ResultFactory
    {
        public:
            Result CreateResult(const Expression &parsedExpression, const float &answer);
    };
}
#endif  // RESULTFACTORY_H