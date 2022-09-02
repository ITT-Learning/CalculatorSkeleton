#include "CalcHistoryTraverser.h"

CalcHistoryTraverser::CalcHistoryTraverser(CalcHistory* p_history)
{
    history = p_history;
    curr = history->newest();
};

std::string CalcHistoryTraverser::next()
{
    if(curr == history->newest())
        return "";
    
    return (++curr)->getEquation();
};

std::string CalcHistoryTraverser::current()
{
    if(curr == history->newest())
        return "";
    
    return curr->getEquation();
};

std::string CalcHistoryTraverser::previous()
{
    if(curr == history->oldest())
        return curr->getEquation();
    
    return (--curr)->getEquation();
};

void CalcHistoryTraverser::reset()
{
    curr = history->newest();
};