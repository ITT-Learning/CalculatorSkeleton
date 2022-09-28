#include "MathExpression.h"

#include <cctype>
#include <sstream>
#include <set>
#include <vector>

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


Result<std::vector<std::string>> MathExpression::getPopulatedEquation() const
{
    std::vector<std::string> populatedEquation;
    for (int i = 0; i < equation_.length(); i++)
    {
        if (equation_[i] == '-')
        {
            if(i + 1 >= equation_.length() ||                                                                   // end of string
               (i > 0 && (isalnum(equation_[i - 1]) || equation_[i - 1] == '.' || equation_[i - 1] == ')')) ||  // previous value supports a subtraction after it
               (!isalnum(equation_[i + 1]) && equation_[i + 1] != '.'))                                         // next value doesn't support negation
            {
                populatedEquation.push_back(std::string(1, equation_[i]));
            }
            else if(isalpha(equation_[i + 1]))
            {
                std::string variableName = extractNextVariableFromString(equation_.substr(i + 1));
                if (variables_.count(variableName) == 0)
                {
                    return Result<std::vector<std::string>>(
                        std::make_unique<std::vector<std::string>>(),
                        false, "Variable value missing");
                }
                i += variableName.length();
                double negativeValue = variables_.at(variableName) * -1;
                std::stringstream sout;
                sout << negativeValue;
                populatedEquation.push_back(sout.str());
            }
            else if(isdigit(equation_[i + 1]) || equation_[i + 1] == '.')
            {
                std::string readNumber = extractNextNumberFromString(equation_.substr(i + 1));
                i += readNumber.length();
                populatedEquation.push_back("-" + readNumber);
            }
        }
        else if (isalpha(equation_[i]))
        {
            std::string variableName = extractNextVariableFromString(equation_.substr(i));
            if (variables_.count(variableName) == 0)
            {
                return Result<std::vector<std::string>>(
                    std::make_unique<std::vector<std::string>>(),
                    false, "Variable value missing");
            }
            i += variableName.length() - 1;
            std::stringstream sout;
            sout << variables_.at(variableName);
            populatedEquation.push_back(sout.str());
        }
        else if (isdigit(equation_[i]) || equation_[i] == '.')
        {
            std::string readNumber = extractNextNumberFromString(equation_.substr(i));
            i += readNumber.length() - 1;
            populatedEquation.push_back(readNumber);
        }
        else
        {
            populatedEquation.push_back(std::string(1, equation_[i]));
        }
    }
    return Result<std::vector<std::string>>(std::make_unique<std::vector<std::string>>(populatedEquation));
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



std::string MathExpression::extractNextNumberFromString(std::string str)
{
    std::string readNumber = "";
    for (int i = 0; i < str.length() && (isdigit(str[i]) || str[i] == '.'); i++)
    {
        readNumber += str[i];
    }
    return readNumber;
};



std::string MathExpression::extractNextVariableFromString(std::string str)
{
    std::string readVariable = "";
    for (int i = 0; i < str.length() && isalpha(str[i]); i++)
    {
        readVariable += str[i];
    }
    return readVariable;
};