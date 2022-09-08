#include "CalcHistoryTraverser.h"

CalcHistoryTraverser::CalcHistoryTraverser(CalcHistory* p_history)
{
    history = p_history;
    reset();
};

std::string CalcHistoryTraverser::next()
{
    if(curr >= history->newest() || history->isEmpty())
        return currentInput;
    if(++curr == history->newest())
        return currentInput;
    return curr->getEquation();
};

std::string CalcHistoryTraverser::current()
{
    if(curr >= history->newest() || history->isEmpty())
        return currentInput;
    
    return curr->getEquation();
};

std::string CalcHistoryTraverser::previous()
{
    if(history->isEmpty())
        return currentInput;
    if(curr <= history->oldest())
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

std::vector<std::string> CalcHistoryTraverser::getHistoryStringWithBounds(int prevSize, int nextSize, int width)
{
    std::vector<std::string> reversePrev;
    if(!history->isEmpty())
        for(std::vector<CalcHistoryPair>::iterator it = curr - 1; it >= history->oldest() && (curr - it) < prevSize; it--)
            reversePrev.push_back(it->getEquation());
    while(reversePrev.size() < prevSize)
        reversePrev.push_back("");
    std::vector<std::string> forwardNext;
    if(!history->isEmpty())
        for(std::vector<CalcHistoryPair>::iterator it = curr + 1; it < history->newest() && (it - curr) < nextSize; it++)
            forwardNext.push_back(it->getEquation());
    if(forwardNext.size() < nextSize && curr != history->newest())
        forwardNext.push_back(currentInput);

    std::vector<std::string> compositeHistory;

    for(std::vector<std::string>::reverse_iterator it = reversePrev.rbegin(); it != reversePrev.rend(); it++)
        compositeHistory.push_back(it->substr(0, width));
    if(curr == history->newest())
        compositeHistory.push_back(currentInput);
    else if(curr != history->newest())
        compositeHistory.push_back(curr->getEquation().substr(0, width));
    for(std::vector<std::string>::iterator it = forwardNext.begin(); it != forwardNext.end(); it++)
        compositeHistory.push_back(it->substr(0, width));

    return compositeHistory;
};

std::vector<std::string> CalcHistoryTraverser::getHistoryStringWithBoundsAndResults(int prevSize, int nextSize, int width)
{
    std::vector<std::string> reversePrev;
    if(!history->isEmpty())
    {
        for(std::vector<CalcHistoryPair>::iterator it = curr - 1; it >= history->oldest() && (curr - it) < prevSize; it--)
        {
            std::string entry = "";
            entry += std::to_string(it->getResult()) + " = ";
            entry += it->getEquation();
            reversePrev.push_back(entry);
        }
    }
    while(reversePrev.size() < prevSize)
        reversePrev.push_back("");
    std::vector<std::string> forwardNext;
    if(!history->isEmpty())
    {
        for(std::vector<CalcHistoryPair>::iterator it = curr + 1; it < history->newest() && (it - curr) < nextSize; it++)
        {
            std::string entry = "";
            entry += std::to_string(it->getResult()) + " = ";
            entry += it->getEquation();
            forwardNext.push_back(entry);
        }
    }
    if(forwardNext.size() < nextSize && curr != history->newest())
    {
        std::string entry = "";
        entry += "? = ";
        entry += currentInput;
        forwardNext.push_back(entry);
    }

    std::vector<std::string> compositeHistory;

    for(std::vector<std::string>::reverse_iterator it = reversePrev.rbegin(); it != reversePrev.rend(); it++)
        compositeHistory.push_back(it->substr(0, width));
    if(curr == history->newest())
        compositeHistory.push_back(currentInput);
    else if(curr != history->newest())
    {
        std::string entry = "";
        if(curr != history->newest())
            entry += std::to_string(curr->getResult()) + " = ";
        entry += curr->getEquation();
        compositeHistory.push_back(entry.substr(0, width));
    }
    for(std::vector<std::string>::iterator it = forwardNext.begin(); it != forwardNext.end(); it++)
        compositeHistory.push_back(it->substr(0, width));

    return compositeHistory;
};