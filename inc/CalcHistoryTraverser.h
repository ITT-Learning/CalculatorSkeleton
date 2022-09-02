#ifndef CALC_HISTORY_TRAVERSER_H
#define CALC_HISTORY_TRAVERSER_H

#include "CalcHistory.h"
#include "CalcHistoryPair.h"
#include <vector>

class CalcHistoryTraverser
{
    private:
        CalcHistory* history;
        std::vector<CalcHistoryPair>::iterator curr;

    public:
        CalcHistoryTraverser(CalcHistory*);
        std::string next();
        std::string current();
        std::string previous();
        void reset();
};

#endif