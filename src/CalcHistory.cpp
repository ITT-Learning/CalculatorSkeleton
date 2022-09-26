#include "CalcHistory.h"

#include <string>
#include <fstream>
#include <sstream>
#include <vector>

#include "CalcHistory_generated.h"
#include "CalcHistoryPair.h"


void CalcHistory::initialzeFromFilePath(std::string filePath)
{
    entries_.clear();

    std::ifstream fin(filePath, std::ios_base::binary);
    fin.seekg(0, std::ios::end);
    int bufferSize = fin.tellg();
    fin.seekg(0, std::ios::beg);    
    char *bufferPointer[bufferSize];
    fin.read((char*)bufferPointer, bufferSize);
    fin.close();

    auto historyBuffer = GetCalcHistoryBuffer(bufferPointer);
    auto historyVector = historyBuffer->history();
    for (int i = 0; i < historyVector->size(); i++)
    {
        auto currentHistoryPair = historyVector->Get(i);
        std::string equationString = currentHistoryPair->equation()->str();
        std::string resultString = currentHistoryPair->result()->str();
        entries_.push_back(CalcHistoryPair(equationString, resultString));
    }
};



void CalcHistory::saveToFilePath(std::string filePath) const
{
    flatbuffers::FlatBufferBuilder builder;
    std::vector<flatbuffers::Offset<CalcHistoryPairBuffer>> historyVector;

    for (auto it = entries_.cbegin(); it != entries_.cend(); it++)
    {
        auto historyEquation = builder.CreateString(it->getEquation());
        auto historyResult = builder.CreateString(it->getResult());

        auto historyItem = CreateCalcHistoryPairBuffer(builder, historyEquation, historyResult);
        historyVector.push_back(historyItem);
    }

    auto historyPairBuffer = builder.CreateVector(historyVector);
    auto historyBuffer = CreateCalcHistoryBuffer(builder, historyPairBuffer);

    builder.Finish(historyBuffer);
    uint8_t *buffer = builder.GetBufferPointer();
    int bufferSize = builder.GetSize();

    std::ofstream fout(filePath, std::ios_base::binary);
    if (!fout.fail())
    {
        for (int i = 0; i < bufferSize; i++)
        {
            fout << buffer[i];
        }
    }
    fout.close();
};



void CalcHistory::addEntry(std::string equation, std::string result)
{
    entries_.push_back(CalcHistoryPair(equation, result));
};



std::string CalcHistory::toString(const CalcHistory& calcHistory)
{
    std::ostringstream strStream;
    strStream << calcHistory;
    return strStream.str();
};



std::ostream& operator << (std::ostream& sout, const CalcHistory& calcHistory)
{
    for (std::vector<CalcHistoryPair>::const_iterator it = calcHistory.entries_.cbegin(); it != calcHistory.entries_.cend(); it++)
    {
        sout << *it;
        if (it != calcHistory.entries_.cend())
        {
            sout << "\n";
        }
    }
    return sout;
};



std::vector<CalcHistoryPair>::const_iterator CalcHistory::newest() const
{
    return entries_.cend();
};



std::vector<CalcHistoryPair>::const_iterator CalcHistory::oldest() const
{
    return entries_.cbegin();
};



bool CalcHistory::isEmpty() const
{
    return entries_.empty();
};