#include "MathExpression.h"

#include <cctype>
#include <sstream>
#include <set>

#include "Result.h"



MathExpression::MathExpression(std::string equation)
: equation_(sanitizeEquation(equation)) {};



std::set<std::string> MathExpression::getVariableNames() const
{
    std::set<std::string> variablesList;

    std::string variableName = "";
    for (int i = 0; i < equation_.length(); i++)
    {
        variableName = "";
        if (isalpha(equation_[i]))
        {
            while (isalpha(equation_[i]) && i < equation_.length())
            {
                variableName += equation_[i++];
            }
            i--;
            variablesList.insert(variableName);
        }
    }
    return variablesList;
};



std::set<std::string> MathExpression::needsVariableValues() const
{

    std::set<std::string> variablesList = getVariableNames(); 
    std::set<std::string> emptyVariablesList; 
    for(auto it = variablesList.cbegin(); it != variablesList.end(); it++)
    {
        if (variables_.count(*it) == 0)
        {
            emptyVariablesList.insert(*it);
        }
    }

    return emptyVariablesList;
};



void MathExpression::setVariableValue(std::string variableName, double value)
{
    variables_.erase  (variableName);
    variables_.emplace(variableName, value);
};



std::string MathExpression::getRawEquation() const
{
    return equation_;
};


// FIXME make negative sign before variables work properly
Result<std::string> MathExpression::getPopulatedEquation() const
{
    std::string populatedEquation = "";
    for (int i = 0; i < equation_.length(); i++)
    {
        std::string variableName = "";
        if (isalpha(equation_[i]))
        {
            while (isalpha(equation_[i]) && i < equation_.length())
            {
                variableName += equation_[i++];
            }
            i--;
            if (variables_.count(variableName) == 0)
            {
                return Result<std::string>(std::make_unique<std::string>(""), false, "Variable value missing");
            }
            std::stringstream sout;
            sout << variables_.at(variableName);
            populatedEquation += sout.str();
        }
        else
        {
            populatedEquation += equation_[i];
        }
    }
    return Result<std::string>(std::make_unique<std::string>(populatedEquation));
};



std::string MathExpression::sanitizeEquation(std::string equation)
{
    std::string sanitizedEquation = "";
    for (int i = 0; i < equation.length(); i++)
    {
        bool isAlphaNumeric = isalnum(equation[i]);
        bool isMathOperator = equation[i] == '(' || 
                              equation[i] == ')' ||
                              equation[i] == '+' ||
                              equation[i] == '-' ||
                              equation[i] == '*' ||
                              equation[i] == '/';
        bool isDecimalPoint = equation[i] == '.';
        if (isAlphaNumeric || isMathOperator || isDecimalPoint)
        {
            sanitizedEquation += tolower(equation[i]);
        }
    }

    return sanitizedEquation;
};