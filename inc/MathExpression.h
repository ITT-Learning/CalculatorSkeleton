#ifndef MATH_EXPRESSION_H
#define MATH_EXPRESSION_H

#include <string>
#include <set>
#include <vector>
#include <unordered_map>

#include "Result.h"

class MathExpression
{
    public:
        MathExpression(std::string equation);

        std::set<std::string> getVariableNames()    const;
        std::set<std::string> needsVariableValues() const;
        void                  setVariableValue(std::string variableName, double value);

        std::string                      getRawEquation()       const;
        Result<std::vector<std::string>> getPopulatedEquation() const;

        static std::string sanitizeEquation(std::string equation);

    private:
        std::string                             equation_;
        std::unordered_map<std::string, double> variables_;

        static std::string extractNextNumberFromString(std::string str);
        static std::string extractNextVariableFromString(std::string str);
};

#endif