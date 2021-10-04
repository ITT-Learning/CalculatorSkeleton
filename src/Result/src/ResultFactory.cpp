////////////////////////////////////////////////////////////////////////////////
/**
* @file ResultFactory.cpp
* @brief Function definitions for Result Factory
*/
////////////////////////////////////////////////////////////////////////////////

#include "Result.h"
#include "ResultFactory.h"
#include <sstream>
#include <iostream>
#include "CalculatorMessages.h"


namespace calculator
{

//*************/
// ResultFactory public methods /
///
   
    Result ResultFactory::createResult(const Expression &parsedExpression, const float answer)
    {
        std::stringstream stringStream;

        stringStream << parsedExpression.a << CalculatorMessages::EMPTY_SPACE 
        << parsedExpression.operation << CalculatorMessages::EMPTY_SPACE 
        << parsedExpression.b << CalculatorMessages::EQUALS << answer << std::endl;
        
        return Result(parsedExpression, answer, stringStream.str());
    }
    
}