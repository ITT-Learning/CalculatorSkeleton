#ifndef CALC_HISTORY_TRAVERSER_H
#define CALC_HISTORY_TRAVERSER_H

#include <vector>
#include <string>

#include "CalcHistory.h"
#include "CalcHistoryPair.h"

class CalcHistoryTraverser
{
    public:
        CalcHistoryTraverser(CalcHistory* calcHistory);

        std::string next();
        std::string current();
        std::string previous();
        
        void reset();
        void setCurrentInput(std::string);

        std::vector<std::string> getHistoryStringWithBounds(int prevSize, int nextSize, int width) const;
        std::vector<std::string> getHistoryStringWithBoundsAndResults(int prevSize, int nextSize, int width) const;

    private:
        CalcHistory* calcHistory_;

        std::vector<CalcHistoryPair>::const_iterator currentPosition_;
        std::string                                  currentInput_;
};

#endif