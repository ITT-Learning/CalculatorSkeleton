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

// TODO probably this function seg faults on no history
std::vector<std::string> CalcHistoryTraverser::getHistoryStringWithBounds(int prevSize, int nextSize, int width, bool withResult = false)
{
    std::vector<std::string> reversePrev;
    for(std::vector<CalcHistoryPair>::iterator it = curr - 1; it >= history->oldest() && (curr - it) < prevSize; it--)
    {
        std::string entry = "";
        if(withResult)
            entry += std::to_string(it->getResult()) + " = ";
        entry += it->getEquation();
        reversePrev.push_back(entry);
    }
    while(reversePrev.size() < prevSize)
        reversePrev.push_back("");
    std::vector<std::string> forwardNext;
    for(std::vector<CalcHistoryPair>::iterator it = curr + 1; it < history->newest() && (it - curr) < nextSize; it++)
    {
        std::string entry = "";
        if(withResult)
            entry += std::to_string(it->getResult()) + " = ";
        entry += it->getEquation();
        forwardNext.push_back(entry);
    }
    if(forwardNext.size() < nextSize && curr != history->newest())
    {
        std::string entry = "";
        if(withResult)
            entry += "? = ";
        entry += currentInput;
        forwardNext.push_back(entry);
    }

    std::vector<std::string> compositeHistory;

    for(std::vector<std::string>::reverse_iterator it = reversePrev.rbegin(); it != reversePrev.rend(); it++)
        compositeHistory.push_back(it->substr(0, width));
    if(curr == history->newest() && !withResult)
        compositeHistory.push_back(currentInput);
    else
    {
        // compositeHistory.push_back(curr->getEquation().substr(0, width));
        std::string entry = "";
        if(withResult && curr != history->newest())
            entry += std::to_string(curr->getResult()) + " = ";
        entry += curr->getEquation();
        compositeHistory.push_back(entry.substr(0, width));
    }
    for(std::vector<std::string>::iterator it = forwardNext.begin(); it != forwardNext.end(); it++)
        compositeHistory.push_back(it->substr(0, width));

    return compositeHistory;
};