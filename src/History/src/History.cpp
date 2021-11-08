////////////////////////////////////////////////////////////////////////////////
/**
* @file History.cpp
* @brief Function definitions for Calculator History
*/
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

#include "CalculatorMessages.h"
#include "flatbuffers/flatbuffers.h"
#include "History.h"
#include "history_generated.h"

namespace calculator
{

// ***************************************************************************** /
// ***************** History public methods ************************************* /
// ***************************************************************************** /

void History::addToHistory(std::string fullResult)
{
    allHistory_.push_back(fullResult);
}

void History::serializeHistory(const std::vector<std::string> &history)
{
    flatbuffers::FlatBufferBuilder builder;
    auto historyBuffer = builder.CreateVectorOfStrings(history);
    schema::HistoryBuilder historyBuilder(builder);
    historyBuilder.add_historyList(historyBuffer);
    auto historyOffset = historyBuilder.Finish();
    builder.Finish(historyOffset);

    historyBufferptr_ = builder.GetBufferPointer();
}

void History::deserializeAndPrintHistory()
{
   auto history = schema::GetHistory(historyBufferptr_)->UnPack();
   
   std::cout << CalculatorMessages::HISTORY_START << std::endl;
   for (size_t i = 0; i < history->historyList.size(); i++)
   {
       std::cout << history->historyList.at(i) << std::endl;
   }
   std::cout << CalculatorMessages::HISTORY_END << std::endl;
}

std::vector<std::string> History::getCurrentHistory()
{
    return allHistory_;
}

} //namespace calculator