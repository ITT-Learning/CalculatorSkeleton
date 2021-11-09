////////////////////////////////////////////////////////////////////////////
/**
 *  @file   main.cpp
 *  @brief  Entry Point of Calculator
 */
////////////////////////////////////////////////////////////////////////////

#include <string>
#include <memory>
#include "flatbuffers/util.h"
#include <fstream>

#include "Calculator.h"
#include "CalculatorMessages.h"
#include "History.h"

int main() 
{

    std::shared_ptr<calculator::History> history = std::make_shared<calculator::History>();
    const char* checkFile = history->getHistoryFileName().c_str();
    if (flatbuffers::FileExists(checkFile))
    {
        history->deserializeHistoryAndPrint(history->getHistoryFileName());
    }

    bool running = true;
    while(running)
    {
        calculator::Calculator calculator;
        calculator.runCalculator(history);
        running = calculator.restart(history);
    }

    return 0;
}
