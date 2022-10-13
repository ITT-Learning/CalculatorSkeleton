#include "HistoryService.h"

#include <string>
#include <sstream>

#include "CalcHistory.h"
#include "CalcHistoryPair.h"
#include "Result.h"


      CalcHistory HistoryService::history_  = CalcHistory();
const std::string HistoryService::filePath_ = std::string(getenv("HOME")) + std::string("/calc/history_api");



std::string HistoryService::getAllHistory()
{
    refreshHistory();

    std::stringstream hout;
    hout << "[";
    if (!history_.isEmpty())
    {
        for (auto it = history_.oldest(); it != history_.newest(); it++)
        {
            if (it != history_.oldest())
            {
                hout << ",";
            };
            hout << "{\"equation\":\"";
            hout << it->getEquation();
            hout << "\",\"result\":";
            hout << it->getResult();
            hout << "}";
        }
    }
    hout << "]";

    return hout.str();
};



Result<std::string> HistoryService::getByIndex(int index)
{
    refreshHistory();

    if (index < 0 || index >= history_.size())
    {
        return Result<std::string>("", false, "Index is out of bounds.");
    }

    auto it = history_.oldest() + index;

    std::stringstream hout;
    hout << "{\"equation\":\"" << it->getEquation() << "\",\"result\":" << it->getResult() << "}";

    return Result<std::string>(hout.str());
};



Result<std::string> HistoryService::deleteByIndex(int index)
{
    refreshHistory();

    Result<std::string> found = getByIndex(index);

    if (!found.isValid())
    {
        return Result<std::string>("", false, found.getError());
    }

    history_.removeEntry(index);
    history_.saveToFilePath(filePath_);

    return Result<std::string>(found.getResult().c_str());
};



void HistoryService::addEntry(const CalcHistoryPair& historyEntry)
{
    refreshHistory();

    history_.addEntry(historyEntry);
    history_.saveToFilePath(filePath_);
};



void HistoryService::refreshHistory()
{
    history_.initialzeFromFilePath(filePath_);
};