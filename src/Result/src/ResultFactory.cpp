////////////////////////////////////////////////////////////////////////////////
/**
* @file ResultFactory.cpp
* @brief Function definitions for Result Factory
*/
////////////////////////////////////////////////////////////////////////////////

#include <memory>
#include <iostream>
#include <sstream>

#include "CalculatorMessages.h"
#include "IResult.h"
#include "Result.h"
#include "ResultFactory.h"


namespace calculator
{

//*************/
// ResultFactory public methods /
///
   
    std::shared_ptr<IResult> ResultFactory::createResult(const Expression &parsedExpression, float answer)
    {
        std::stringstream stringStream;
        
        stringStream << parsedExpression.a << CalculatorMessages::EMPTY_SPACE 
        << parsedExpression.operation << CalculatorMessages::EMPTY_SPACE 
        << parsedExpression.b << CalculatorMessages::EQUALS << answer << std::endl;
        
        return std::make_shared<Result>(parsedExpression, answer, stringStream.str());
    }
}
