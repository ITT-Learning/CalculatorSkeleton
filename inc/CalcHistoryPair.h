#ifndef CALC_HISTORY_PAIR_H
#define CALC_HISTORY_PAIR_H

#include <ostream>
#include <string>

class CalcHistoryPair
{
    private:
        std::string equation;
        double result;

        friend std::ostream& operator << (std::ostream&, const CalcHistoryPair&);

    
    public:
        CalcHistoryPair(std::string, double);
        std::string getEquation();
        double getResult();
};

std::ostream& operator << (std::ostream&, const CalcHistoryPair&);

#endif