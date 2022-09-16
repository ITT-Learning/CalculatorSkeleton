#include "MathResult.h"

#include <cmath>
#include <sstream>



int findPrecisionFor(double number, int decimalDigits = 4)
{
    int baseLog = (int)log10(std::abs(number));
    int effectiveLog = std::max(baseLog + 1 + decimalDigits, baseLog * - 1);
    return effectiveLog;
};



std::string doubleToString(double number)
{
    std::stringstream ss;
    ss.precision(findPrecisionFor(number));
    ss << number;
    return ss.str();
};



MathResult::MathResult(double result)
{
    result_ = result;
    isValid_ = ! std::isnan(result_);
    errorMessage_ = isValid_ ? "" : "Not a number";
};



MathResult::MathResult(std::string errorMessage)
: result_(nan("")), isValid_(false), errorMessage_{errorMessage} {};



bool MathResult::isValid() const
{
    return isValid_;
};



std::string MathResult::getResultString() const
{
    if(isValid_)
    {
        return doubleToString(result_);
    }
    else
    {
        return errorMessage_;
    }
};