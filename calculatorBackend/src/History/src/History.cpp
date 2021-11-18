////////////////////////////////////////////////////////////////////////////////
/**
* @file History.cpp
* @brief Function definitions for Calculator History
*/
////////////////////////////////////////////////////////////////////////////////

#include <fstream>
#include <iostream>
#include <vector>

#include "CalculatorMessages.h"
#include "flatbuffers/flatbuffers.h"
#include "flatbuffers/idl.h"
#include "flatbuffers/util.h"
#include "History.h"
#include "history_generated.h"

namespace calculator {

// ***************************************************************************** /
// ***************** History public methods ************************************ /
// ***************************************************************************** /

History::History()
{
    loadHistory();
    printHistory();
}

void History::addToHistory(std::string const &fullResult)
{
    allHistory_.clear();

    if(!hasHistoryFile_)
    {
        saveHistory(allHistory_);
    }

    deserializeHistory();
    allHistory_.push_back(fullResult);
    saveHistory(allHistory_);
}

void History::printHistory()
{
    if (allHistory_.size() > 0)
    {
        std::cout << CalculatorMessages::HISTORY_START << std::endl;
        for (auto &history : allHistory_)
        {
            std::cout << history << std::endl;
        }
        std::cout << CalculatorMessages::HISTORY_END << std::endl;
    }
    else
    {
        std::cout << CalculatorMessages::NO_HISTORY << std::endl;
    }
}

// ***************************************************************************** /
// ***************** History private methods *********************************** /
// ***************************************************************************** /

bool History::loadHistory()
{
    bool hasHistory = false;
    const char* checkFile = historyFile_.c_str();
    if (flatbuffers::FileExists(checkFile))
    {
        hasHistory = true;
        deserializeHistory();
    }
    hasHistoryFile_ = hasHistory;

    return hasHistory;
}

void History::deserializeHistory()
{
    std::ifstream infile;
    infile.open(historyFile_, std::ios::binary | std::ios::in);
    infile.seekg(0, std::ios::end);
    int length = infile.tellg();
    infile.seekg(0, std::ios::beg);
    char* data = new char[length];
    infile.read(data, length);
    infile.close();

    allHistory_ = schema::GetHistory(data)->UnPack()->historyList;
    delete[] data;
}

void History::saveHistory(const std::vector<std::string> &history)
{
    flatbuffers::FlatBufferBuilder builder;
    auto historyBuffer = builder.CreateVectorOfStrings(history);
    schema::HistoryBuilder historyBuilder(builder);
    historyBuilder.add_historyList(historyBuffer);
    auto historyOffset = historyBuilder.Finish();
    builder.Finish(historyOffset);

    std::ofstream ofStream(historyFile_, std::ofstream::binary);
    ofStream.write((char*)builder.GetBufferPointer(), builder.GetSize());
    ofStream.close();
}

} //namespace calculator