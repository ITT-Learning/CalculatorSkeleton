#include "CalcHistory.h"

#include <fstream>
#include <sstream>

const std::string CalcHistory::filePath_ = std::string(getenv("HOME")) + "/calc/history.txt";



CalcHistory::CalcHistory()
{
    std::ifstream fin(filePath_);
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



CalcHistory::~CalcHistory()
{
    std::ofstream fout(filePath_);
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



std::vector<CalcHistoryPair>::iterator CalcHistory::newest()
{
    return entries_.end();
};



std::vector<CalcHistoryPair>::iterator CalcHistory::oldest()
{
    return entries_.begin();
};



bool CalcHistory::isEmpty()
{
    return entries_.empty();
};