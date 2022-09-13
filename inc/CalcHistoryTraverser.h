#ifndef CALC_HISTORY_TRAVERSER_H
#define CALC_HISTORY_TRAVERSER_H

#include "CalcHistory.h"
#include "CalcHistoryPair.h"
#include <vector>
#include <string>

class CalcHistoryTraverser
{
    public:
        CalcHistoryTraverser(CalcHistory* calcHistory);

        std::string next();
        std::string current();
        std::string previous();
        
        void reset();
        void setCurrentInput(std::string);

        std::vector<std::string> getHistoryStringWithBounds(int prevSize, int nextSize, int width);
        std::vector<std::string> getHistoryStringWithBoundsAndResults(int prevSize, int nextSize, int width);

    private:
        CalcHistory* calcHistory_;
        std::vector<CalcHistoryPair>::iterator currentPosition_;
        std::string currentInput_;
};

#endif