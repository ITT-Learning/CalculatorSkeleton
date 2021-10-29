#ifndef RESULTFACTORY_H
#define RESULTFACTORY_H

////////////////////////////////////////////////////////////////////////////////
/**
* @file ResultFactory.h
* @brief Result Object function declarations.
*/
////////////////////////////////////////////////////////////////////////////////

#include <memory>

#include "Result.h"
#include "IResult.h"
#include "ResultFactory.h"

namespace calculator {

/**
* @brief ResultFactory interface which exposes to other components
*/

class ResultFactory
{
    public:
        /**
         * @brief creates a result object with a parsedExpression, an answer, and puts together the full result
         * @param originalEquation is the original input entered
         * @param answer is the answer to the expression, created by the calculate
         * @returns a pointer to an IResult
        */
        std::shared_ptr<IResult> createResult(const std::string &originalEquation, float answer);
};

} //namespace calculator

#endif  // RESULTFACTORY_H
