////////////////////////////////////////////////////////////////////////////////
/**
* @file ResultFactory.cpp
* @brief Function definitions for Result Factory
*/
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <sstream>

#include "CalculatorMessages.h"
#include "Result.h"
#include "ResultFactory.h"


namespace calculator
{

//*************/
// ResultFactory public methods /
///
   
    Result ResultFactory::createResult(const Expression &parsedExpression, float answer)
    {
        std::stringstream stringStream;
        
        stringStream << parsedExpression.a << CalculatorMessages::EMPTY_SPACE 
        << parsedExpression.operation << CalculatorMessages::EMPTY_SPACE 
        << parsedExpression.b << CalculatorMessages::EQUALS << answer << std::endl;
        
        return Result(parsedExpression, answer, stringStream.str());
    }
    
}