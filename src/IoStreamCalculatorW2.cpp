/**
 * @file IoStreamCalculatorW2.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-07-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../inc/IoStreamCalculatorW2.h"
#include "../inc/CalculatorStrings.h"

namespace calculatorw2
{
    IoStreamCalculatorW2::IoStreamCalculatorW2(std::istream& inputStream, std::ostream& outputStream) : error_(nullptr), inputStream_(inputStream), outputStream_(outputStream)
    {

    }

    IoStreamCalculatorW2::~IoStreamCalculatorW2()
    {
        
    }

    void IoStreamCalculatorW2::OutputHelloAndHelp()
    {
        std::cout << helloMessage << std::endl;
        std::cout << helpMessage << std::endl;
    }

    void IoStreamCalculatorW2::Run()
    {   
        error_ = nullptr;
        double left, right, result;
        char op = (char)Operators::NOOP;
        std::string extendedInformation;

        TokenizerW2 *tokenizer = TokenizerW2::createTokenizer(inputStream_);

        while (op != (char)Operators::QUIT)
        {
            error_ = tokenizer->getControlExpression(op, extendedInformation);

            if (error_ == nullptr)
            {
                error_ = tokenizer->getMathExpression(left, right, op);
                if(error_ == nullptr)
                {
                    result = calculatorW2_.calculate(left, right, op);
                    error_ = calculatorW2_.getError();
                }
            }

            if(error_ == nullptr)
            {
                outputStream_ << "= " << result << std::endl;
            }
            else
            {
                outputStream_ << error_ << std::endl;
            }

            delete tokenizer;
            if (op != (char)Operators::QUIT)
            {    
                tokenizer = TokenizerW2::createTokenizer(inputStream_);
            }
        }
    }
}