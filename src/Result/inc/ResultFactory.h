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
namespace calculator
{
    class ResultFactory
    {
        public:
            /**
             * @brief creates a result object with a parsedExpression, an answer, and puts together the full result
             * @param parsedExpression is the expression object that was created and parsed in the parser
             * @param answer is the answer to the expression, created by the calculate
             * @param fullResult is a string stream that combines all other variables and some calculatorMessages
            */
            std::shared_ptr<IResult> createResult(const Expression &parsedExpression, float answer);
    };
}
#endif  // RESULTFACTORY_H