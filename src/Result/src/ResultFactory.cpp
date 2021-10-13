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
   
    std::shared_ptr<IResult> ResultFactory::createResult(const std::string &originalEquation, float answer)
    {
        std::stringstream stringStream;
        
        stringStream << originalEquation << CalculatorMessages::EQUALS << answer << std::endl;
        
        return std::make_shared<Result>(originalEquation, answer, stringStream.str());
    }
}
