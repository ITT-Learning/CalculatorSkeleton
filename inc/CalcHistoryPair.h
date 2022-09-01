#ifndef CALC_HISTORY_PAIR_H
#define CALC_HISTORY_PAIR_H

#include <ostream>
#include <string>

class CalcHistoryPair
{
    private:
        std::string equation;
        double result;

        friend std::ostream& operator << (std::ostream&, CalcHistoryPair&);

    
    public:
        CalcHistoryPair(std::string, double);
};

std::ostream& operator << (std::ostream&, CalcHistoryPair&);

#endif