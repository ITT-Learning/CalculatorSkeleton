#ifndef CALC_HISTORY_H
#define CALC_HISTORY_H

#include <string>
#include <fstream>
#include <ostream>
#include <vector>

#include "CalcHistoryPair.h"

class CalcHistory
{
    private:
        static const std::string filePath;
        std::vector<CalcHistoryPair> entries;

        friend std::ostream& operator << (std::ostream&, const CalcHistory&);

    public:
        CalcHistory();
        ~CalcHistory();

        static std::string toString(const CalcHistory&);

        void addEntry(std::string, double);

        std::vector<CalcHistoryPair>::iterator oldest();
        std::vector<CalcHistoryPair>::iterator newest();

};

std::ostream& operator << (std::ostream&, const CalcHistory&);

#endif