#include "CalcHistoryPair.h"

#include <math.h>
#include <sstream>

int findPrecisionFor(int number, int decimalDigits = 4)
{
    int baseLog = (int)log10(std::abs(number));
    int effectiveLog = std::max(baseLog + 1 + decimalDigits, baseLog * - 1);
    return effectiveLog;
};



CalcHistoryPair::CalcHistoryPair(std::string equation, double result)
: equation_{equation}, result_{result} {};



std::ostream& operator << (std::ostream& sout, const CalcHistoryPair& calcHistoryPair)
{
    sout.precision(findPrecisionFor(calcHistoryPair.result_));
    sout << calcHistoryPair.result_ << " = " << calcHistoryPair.equation_;
    return sout;
};



std::string CalcHistoryPair::getEquation() const
{
    return equation_;
};



double CalcHistoryPair::getResult() const
{
    return result_;
};



std::string CalcHistoryPair::getResultString() const
{
    std::stringstream ss;
    ss << result_;
    return ss.str();
};



std::string CalcHistoryPair::doubleToString(double number)
{
    std::stringstream ss;
    ss << number;
    return ss.str();
};