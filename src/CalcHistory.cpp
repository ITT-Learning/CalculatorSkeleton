#include "CalcHistory.h"
#include <fstream>
#include <sstream>

const std::string CalcHistory::filePath = std::string(getenv("HOME")) + "/calc/history.txt";

CalcHistory::CalcHistory()
{
    std::ifstream fin(filePath);
    while(!fin.eof() && !fin.fail())
    {
        std::string equation;
        std::string resultStr;
        double result;
        getline(fin, resultStr, '=');
        fin.ignore(1); // ignore the space after the equals
        if(fin.eof())
            break;
        getline(fin, equation);
        result = stod(resultStr);
        entries.push_back(CalcHistoryPair(equation, result));
    }
    fin.close();
};

CalcHistory::~CalcHistory()
{
    std::ofstream fout(filePath);
    if(!fout.fail())
        fout << *this;
    fout.close();
};

void CalcHistory::addEntry(std::string equation, double result)
{
    entries.push_back(CalcHistoryPair(equation, result));
};

std::string CalcHistory::toString(const CalcHistory& history)
{
    std::ostringstream strStream;
    strStream << history;
    return strStream.str();
};

std::ostream& operator << (std::ostream& sout, const CalcHistory& calcHistory)
{
    for(std::vector<CalcHistoryPair>::const_iterator it = calcHistory.entries.cbegin(); it != calcHistory.entries.cend(); it++)
    {
        sout << *it;
        if(it != calcHistory.entries.cend())
            sout << "\n";
    }
    return sout;
};

std::vector<CalcHistoryPair>::iterator CalcHistory::newest()
{
    return entries.end();
};

std::vector<CalcHistoryPair>::iterator CalcHistory::oldest()
{
    return entries.begin();
};

bool CalcHistory::isEmpty()
{
    return entries.empty();
};