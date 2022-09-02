#include "CalcHistoryPair.h"

CalcHistoryPair::CalcHistoryPair(std::string p_equation, double p_result)
{
    equation = p_equation;
    result = p_result;
};

std::ostream& operator << (std::ostream& sout, const CalcHistoryPair& chp)
{
    sout << chp.result << " = " << chp.equation;
    return sout;
};