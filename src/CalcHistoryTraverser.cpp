#include "CalcHistoryTraverser.h"

CalcHistoryTraverser::CalcHistoryTraverser(CalcHistory* p_history)
{
    history = p_history;
    curr = history->newest();
    currentInput = "";
};

std::string CalcHistoryTraverser::next()
{
    if(curr == history->newest())
        return currentInput;
    if(++curr == history->newest())
        return currentInput;
    return curr->getEquation();
};

std::string CalcHistoryTraverser::current()
{
    if(curr == history->newest())
        return currentInput;
    
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
    currentInput = "";
};

void CalcHistoryTraverser::setCurrentInput(std::string newInput)
{
    curr = history->newest();
    currentInput = newInput;
};

std::vector<std::string> CalcHistoryTraverser::getHistoryStringWithBounds(int prevSize, int nextSize)
{
    std::vector<std::string> reversePrev;
    for(std::vector<CalcHistoryPair>::iterator it = curr - 1; it >= history->oldest() && (curr - it) < prevSize; it--)
        reversePrev.push_back(it->getEquation());
    while(reversePrev.size() < prevSize)
        reversePrev.push_back("");
    std::vector<std::string> forwardNext;
    for(std::vector<CalcHistoryPair>::iterator it = curr + 1; it < history->newest() && (it - curr) < nextSize; it++)
        forwardNext.push_back(it->getEquation());
    if(forwardNext.size() < nextSize && curr != history->newest())
        forwardNext.push_back(currentInput);

    std::vector<std::string> compositeHistory;

    for(std::vector<std::string>::reverse_iterator it = reversePrev.rbegin(); it != reversePrev.rend(); it++)
        compositeHistory.push_back(it->substr(0, 25));
    if(curr == history->newest())
        compositeHistory.push_back(currentInput);
    else
        compositeHistory.push_back(curr->getEquation().substr(0, 25));
    for(std::vector<std::string>::iterator it = forwardNext.begin(); it != forwardNext.end(); it++)
        compositeHistory.push_back(it->substr(0, 25));

    return compositeHistory;
};