////////////////////////////////////////////////////////////////////////////////
/**
* @file Result.cpp
* @brief Function definitions for Result object
*/
////////////////////////////////////////////////////////////////////////////////
#include "Result.h"
#include <iostream>

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