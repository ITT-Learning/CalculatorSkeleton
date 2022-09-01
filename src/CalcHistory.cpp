#include "CalcHistory.h"
#include <fstream>

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

std::ostream& operator << (std::ostream& sout, CalcHistory& calcHistory)
{
    for(std::vector<CalcHistoryPair>::iterator it = calcHistory.entries.begin(); it != calcHistory.entries.end(); it++)
    {
        sout << "  " << *it;
        if(it != calcHistory.entries.end())
            sout << "\n";
    }
    return sout;
};