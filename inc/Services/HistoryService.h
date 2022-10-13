#ifndef SERVICES_HISTORY_SERVICE_H
#define SERVICES_HISTORY_SERVICE_H

#include <string>
#include <vector>

#include "CalcHistory.h"
#include "CalcHistoryPair.h"
#include "Result.h"


class HistoryService
{
    public:
        static std::string         getAllHistory();
        static Result<std::string> getByIndex   (int index);
        static Result<std::string> deleteByIndex(int index);

        static void        addEntry     (const CalcHistoryPair& historyEntry);

    private:
        static       CalcHistory history_;
        static const std::string filePath_;
        static       void        refreshHistory();

        static std::string sanitizeEntry(const std::vector<CalcHistoryPair>::const_iterator& it);

        HistoryService() {};
};

#endif