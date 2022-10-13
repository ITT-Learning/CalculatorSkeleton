#include "HistoryService.h"

#include <string>
#include <sstream>
#include <vector>

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
            hout << sanitizeEntry(it);
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

    return Result<std::string>(sanitizeEntry(it));
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



std::string HistoryService::sanitizeEntry(const std::vector<CalcHistoryPair>::const_iterator& it)
{
    std::stringstream sout;
    sout << "{\"equation\":\"";
    sout << it->getEquation();
    sout << "\",\"result\":";
    const std::string result = it->getResult();
    sout << (result == "nan" ? "\"nan\"" : result) ;
    sout << "}";
    return sout.str();
}