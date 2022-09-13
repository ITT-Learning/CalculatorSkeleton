#ifndef CALC_HISTORY_H
#define CALC_HISTORY_H

#include <ostream>
#include <fstream>
#include <string>
#include <vector>

#include "CalcHistoryPair.h"

class CalcHistory
{
    public:
        CalcHistory();
        ~CalcHistory();

        static std::string toString(const CalcHistory& calcHistory);

        void addEntry(std::string equation, double result);

        std::vector<CalcHistoryPair>::iterator oldest();
        std::vector<CalcHistoryPair>::iterator newest();

        bool isEmpty();

    private:
        static const std::string filePath_;
        std::vector<CalcHistoryPair> entries_;

        friend std::ostream& operator << (std::ostream& sout, const CalcHistory& calcHistory);
};

std::ostream& operator << (std::ostream&, const CalcHistory&);

#endif