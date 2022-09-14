#ifndef CALC_HISTORY_PAIR_H
#define CALC_HISTORY_PAIR_H

#include <ostream>
#include <string>

class CalcHistoryPair
{
    public:
        CalcHistoryPair(std::string equation, double result);
        std::string getEquation() const;
        double getResult() const;
        std::string getResultString() const;

        static std::string doubleToString(double number);
        
    private:
        std::string equation_;
        double result_;

        friend std::ostream& operator << (std::ostream& sout, const CalcHistoryPair& calcHistoryPair);
};

std::ostream& operator << (std::ostream& sout, const CalcHistoryPair& calcHistoryPair);

#endif