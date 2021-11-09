////////////////////////////////////////////////////////////////////////////////
/**
* @file History.cpp
* @brief Function definitions for Calculator History
*/
////////////////////////////////////////////////////////////////////////////////
#include <fstream>
#include <iostream>

#include "CalculatorMessages.h"
#include "flatbuffers/flatbuffers.h"
#include "flatbuffers/util.h"
#include "History.h"
#include "history_generated.h"
#include "flatbuffers/idl.h"

namespace calculator
{

// ***************************************************************************** /
// ***************** History public methods ************************************* /
// ***************************************************************************** /

void History::addToHistory(std::string fullResult)
{
    allHistory_.push_back(fullResult);
}

void History::serializeHistoryAndStoreOnDisk(const std::vector<std::string> &history)
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

void History::deserializeHistoryAndPrint(const std::string & fileName)
{
    std::ifstream infile;
	infile.open(fileName, std::ios::binary | std::ios::in);
	infile.seekg(0, std::ios::end);
	int length = infile.tellg();
	infile.seekg(0, std::ios::beg);
	char* data = new char[length];
	infile.read(data, length);
	infile.close();

	auto history = schema::GetHistory(data);
    auto historyData = history->UnPack();

    allHistory_.clear();

    std::cout << CalculatorMessages::HISTORY_START << std::endl;
    for (size_t i = 0; i < historyData->historyList.size(); i++)
    {
        std::cout << historyData->historyList.at(i) << std::endl;
        allHistory_.push_back(historyData->historyList.at(i));
    }
    std::cout << CalculatorMessages::HISTORY_END << std::endl;
}

std::vector<std::string> History::getCurrentHistory()
{
    return allHistory_;
}

std::string History::getHistoryFileName()
{
    return historyFile_;
}

} //namespace calculator