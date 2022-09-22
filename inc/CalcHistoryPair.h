#ifndef CALC_HISTORY_PAIR_H
#define CALC_HISTORY_PAIR_H

#include <ostream>
#include <string>

class CalcHistoryPair
{
    public:
        CalcHistoryPair(std::string equation, std::string result);
        std::string getEquation() const;
        std::string getResult() const;
        
    private:
        std::string equation_;
        std::string result_;

        friend std::ostream& operator << (std::ostream& sout, const CalcHistoryPair& calcHistoryPair);
};

std::ostream& operator << (std::ostream& sout, const CalcHistoryPair& calcHistoryPair);

#endif