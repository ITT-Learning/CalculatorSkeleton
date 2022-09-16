#include "CalcHistoryPair.h"

#include <sstream>



CalcHistoryPair::CalcHistoryPair(std::string equation, std::string result)
: equation_{equation}, result_{result} {};



std::ostream& operator << (std::ostream& sout, const CalcHistoryPair& calcHistoryPair)
{
    // sout.precision(findPrecisionFor(calcHistoryPair.result_));
    sout << calcHistoryPair.result_ << " = " << calcHistoryPair.equation_;
    return sout;
};



std::string CalcHistoryPair::getEquation() const
{
    return equation_;
};



std::string CalcHistoryPair::getResult() const
{
    return result_;
};



// std::string CalcHistoryPair::getResultString() const
// {
//     std::stringstream ss;
//     ss << result_;
//     return ss.str();
// };