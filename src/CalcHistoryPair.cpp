#include "CalcHistoryPair.h"
#include <math.h>
#include <sstream>

int findPrecisionFor(int number, int decimalDigits = 4)
{
    int baseLog = (int)log10(std::abs(number));
    int effectiveLog = std::max(baseLog + 1 + decimalDigits, baseLog * - 1);
    return effectiveLog;
};

CalcHistoryPair::CalcHistoryPair(std::string p_equation, double p_result)
{
    equation = p_equation;
    result = p_result;
};

std::ostream& operator << (std::ostream& sout, const CalcHistoryPair& chp)
{
    sout.precision(findPrecisionFor(chp.result));
    sout << chp.result << " = " << chp.equation;
    return sout;
};

std::string CalcHistoryPair::getEquation()
{
    return equation;
};

double CalcHistoryPair::getResult()
{
    return result;
};

std::string CalcHistoryPair::getResultString()
{
    std::stringstream ss;
    ss << result;
    return ss.str();
};

std::string CalcHistoryPair::doubleToString(double number)
{
    std::stringstream ss;
    ss << number;
    return ss.str();
};