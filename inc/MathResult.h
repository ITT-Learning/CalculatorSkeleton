#ifndef MATH_RESULT_H
#define MATH_RESULT_H

#include <string>

class MathResult
{
    public:
        MathResult(double result);
        MathResult(std::string errorMessage);

        std::string  getResultString() const;
        bool         isValid()         const;

    private:
        double       result_;
        std::string  errorMessage_;
        bool         isValid_;
};

#endif