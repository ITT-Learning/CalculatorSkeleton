/**
 * @file TokenizerW2.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-07-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "TokenizerW2.h"
#include "CalculatorStrings.h"
#include <sstream>

namespace calculatorw2
{
    TokenizerW2* TokenizerW2::createTokenizer(std::istream& input)
    {
        std::string inputString;
        std::getline(input, inputString);
        
        TokenizerW2* tokenizerW2Ptr = new TokenizerW2(inputString);
        return tokenizerW2Ptr;
    }

    TokenizerW2::TokenizerW2(std::string input): input_(input)
    {

    }

    TokenizerW2::~TokenizerW2()
    {
        
    }

    const char* TokenizerW2::getControlExpression(char& controlOperator, std::string& extendedInformation)
    {
        error_ = nullptr;
        controlOperator = (char)Operators::NOOP;
        std::istringstream inputStream(input_);

        inputStream >> controlOperator >> std::ws;
        std::getline(inputStream, extendedInformation);

        if (controlOperator == (char)Operators::QUIT)
        {
            error_ = quitMessage;
        }

        return error_;
    }

    const char* TokenizerW2::getMathExpression(double& left, double& right, char& mathOperator)
    {
        error_ = nullptr;
        mathOperator = (char)Operators::NOOP;
        std::istringstream inputStream(input_);

        inputStream >> left >> mathOperator >> right;

        return error_;
    }
}