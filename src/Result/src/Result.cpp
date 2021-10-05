////////////////////////////////////////////////////////////////////////////////
/**
* @file Result.cpp
* @brief Function definitions for Result object
*/
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

#include "Result.h"

namespace calculator
{

//*************/
// ResultFactory public methods /
///
   
    std::string Result::getFullResult()
    {
        return fullResult_;
    }

}