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

        friend std::ostream& operator << (std::ostream&, CalcHistory&);

    public:
        CalcHistory();
        ~CalcHistory();

        void addEntry(std::string, double);

};

std::ostream& operator << (std::ostream&, CalcHistory&);

#endif