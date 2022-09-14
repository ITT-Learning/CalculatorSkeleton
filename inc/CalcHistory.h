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
        void initialzeFromFilePath(std::string filePath);
        void saveToFilePath(std::string filePath) const;

        static std::string toString(const CalcHistory& calcHistory);

        void addEntry(std::string equation, double result);

        std::vector<CalcHistoryPair>::const_iterator oldest() const;
        std::vector<CalcHistoryPair>::const_iterator newest() const;

        bool isEmpty() const;

    private:
        std::vector<CalcHistoryPair> entries_;

        friend std::ostream& operator << (std::ostream& sout, const CalcHistory& calcHistory);
};

std::ostream& operator << (std::ostream&, const CalcHistory&);

#endif