#ifndef CALC_HISTORY_TRAVERSER_H
#define CALC_HISTORY_TRAVERSER_H

#include "CalcHistory.h"
#include "CalcHistoryPair.h"
#include <vector>
#include <string>

class CalcHistoryTraverser
{
    private:
        CalcHistory* history;
        std::vector<CalcHistoryPair>::iterator curr;
        std::string currentInput;

    public:
        CalcHistoryTraverser(CalcHistory*);
        std::string next();
        std::string current();
        std::string previous();
        void reset();

        void setCurrentInput(std::string);
        std::vector<std::string> getHistoryStringWithBounds(int prevSize, int nextSize, int width, bool withResult);
};

#endif