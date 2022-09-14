#include "CalcHistory.h"

#include <string>
#include <fstream>
#include <sstream>

#include "CalcHistoryPair.h"


// TODO use flat buffer
void CalcHistory::initialzeFromFilePath(std::string filePath)
{
    entries_.clear();
    std::ifstream fin(filePath);
    while (!fin.eof() && !fin.fail())
    {
        std::string equation;
        std::string resultString;
        double result;

        getline(fin, resultString, '=');

        fin.ignore(1); // ignore the space after the equals
        if (fin.eof())
        {
            break;
        }

        getline(fin, equation);
        result = stod(resultString);

        entries_.push_back(CalcHistoryPair(equation, result));
    }
    fin.close();
};



void CalcHistory::saveToFilePath(std::string filePath) const
{
    std::ofstream fout(filePath);
    if (!fout.fail())
    {
        fout << *this;
    }
    fout.close();
};



void CalcHistory::addEntry(std::string equation, double result)
{
    entries_.push_back(CalcHistoryPair(equation, result));
};



std::string CalcHistory::toString(const CalcHistory& calcHistory)
{
    std::ostringstream strStream;
    strStream << calcHistory;
    return strStream.str();
};



std::ostream& operator << (std::ostream& sout, const CalcHistory& calcHistory)
{
    for(std::vector<CalcHistoryPair>::const_iterator it = calcHistory.entries_.cbegin(); it != calcHistory.entries_.cend(); it++)
    {
        sout << *it;
        if (it != calcHistory.entries_.cend())
        {
            sout << "\n";
        }
    }
    return sout;
};



std::vector<CalcHistoryPair>::const_iterator CalcHistory::newest() const
{
    return entries_.cend();
};



std::vector<CalcHistoryPair>::const_iterator CalcHistory::oldest() const
{
    return entries_.cbegin();
};



bool CalcHistory::isEmpty() const
{
    return entries_.empty();
};