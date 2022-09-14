#include "CalcHistoryTraverser.h"

#include <memory>

#include "CalcHistory.h"

CalcHistoryTraverser::CalcHistoryTraverser(CalcHistory* calcHistory)
: calcHistory_{calcHistory}
{
    reset();
};



std::string CalcHistoryTraverser::next()
{
    if (currentPosition_ >= calcHistory_->newest() || calcHistory_->isEmpty())
    {
        return currentInput_;
    }
    if (++currentPosition_ == calcHistory_->newest())
    {
        return currentInput_;
    }

    return currentPosition_->getEquation();
};



std::string CalcHistoryTraverser::current()
{
    if (currentPosition_ >= calcHistory_->newest() || calcHistory_->isEmpty())
    {
        return currentInput_;
    }
    
    return currentPosition_->getEquation();
};



std::string CalcHistoryTraverser::previous()
{
    if (calcHistory_->isEmpty())
    {
        return currentInput_;
    }
    if (currentPosition_ == calcHistory_->oldest())
    {
        return currentPosition_->getEquation();
    }
    
    return (--currentPosition_)->getEquation();
};



void CalcHistoryTraverser::reset()
{
    currentPosition_ = calcHistory_->newest();
    currentInput_ = "";
};



void CalcHistoryTraverser::setCurrentInput(std::string newInput)
{
    currentPosition_ = calcHistory_->newest();
    currentInput_ = newInput;
};



std::vector<std::string> CalcHistoryTraverser::getHistoryStringWithBounds(int prevSize, int nextSize, int width) const
{
    std::vector<std::string> reversePrev;
    if (!calcHistory_->isEmpty())
    {
        for(std::vector<CalcHistoryPair>::const_iterator it = currentPosition_ - 1; it >= calcHistory_->oldest() && (currentPosition_ - it) < prevSize; it--)
        {
            reversePrev.push_back(it->getEquation().substr(0, width));
        }
    }
    while (reversePrev.size() < prevSize)
    {
        reversePrev.push_back("");
    }
    std::vector<std::string> forwardNext;
    if (!calcHistory_->isEmpty())
    {
        for(std::vector<CalcHistoryPair>::const_iterator it = currentPosition_ + 1; it < calcHistory_->newest() && (it - currentPosition_) < nextSize; it++)
        {
            forwardNext.push_back(it->getEquation().substr(0, width));
        }
    }
    if (forwardNext.size() < nextSize && currentPosition_ != calcHistory_->newest())
    {
        forwardNext.push_back(currentInput_.substr(0, width));
    }

    std::vector<std::string> compositeHistory;

    for(std::vector<std::string>::const_reverse_iterator it = reversePrev.rbegin(); it != reversePrev.rend(); it++)
    {
        compositeHistory.push_back(*it);
    }

    if (currentPosition_ == calcHistory_->newest())
    {
        compositeHistory.push_back(currentInput_.substr(0, width));
    }
    else if (currentPosition_ != calcHistory_->newest())
    {
        compositeHistory.push_back(currentPosition_->getEquation().substr(0, width));
    }

    for(std::vector<std::string>::const_iterator it = forwardNext.begin(); it != forwardNext.end(); it++)
    {
        compositeHistory.push_back(*it);
    }

    return compositeHistory;
};



std::vector<std::string> CalcHistoryTraverser::getHistoryStringWithBoundsAndResults(int prevSize, int nextSize, int width) const
{
    std::vector<std::string> reversePrev;
    if (!calcHistory_->isEmpty())
    {
        for(std::vector<CalcHistoryPair>::const_iterator it = currentPosition_ - 1; it >= calcHistory_->oldest() && (currentPosition_ - it) < prevSize; it--)
        {
            std::string entry = "";
            entry += it->getResultString() + " = ";
            entry += it->getEquation();
            reversePrev.push_back(entry);
        }
    }
    while (reversePrev.size() < prevSize)
    {
        reversePrev.push_back("");
    }
    std::vector<std::string> forwardNext;
    if (!calcHistory_->isEmpty())
    {
        for(std::vector<CalcHistoryPair>::const_iterator it = currentPosition_ + 1; it < calcHistory_->newest() && (it - currentPosition_) < nextSize; it++)
        {
            std::string entry = "";
            entry += it->getResultString() + " = ";
            entry += it->getEquation();
            forwardNext.push_back(entry.substr(0, width));
        }
    }
    if (forwardNext.size() < nextSize && currentPosition_ != calcHistory_->newest())
    {
        std::string entry = "";
        entry += "? = ";
        entry += currentInput_;
        forwardNext.push_back(entry.substr(0, width));
    }

    std::vector<std::string> compositeHistory;

    for(std::vector<std::string>::const_reverse_iterator it = reversePrev.rbegin(); it != reversePrev.rend(); it++)
    {
        compositeHistory.push_back(*it);
    }
    if (currentPosition_ == calcHistory_->newest())
    {
        compositeHistory.push_back(currentInput_.substr(0, width));
    }
    else if (currentPosition_ != calcHistory_->newest())
    {
        std::string entry = "";
        if (currentPosition_ != calcHistory_->newest())
        {
            entry += currentPosition_->getResultString() + " = ";
        }
        entry += currentPosition_->getEquation();
        compositeHistory.push_back(entry.substr(0, width));
    }
    for(std::vector<std::string>::const_iterator it = forwardNext.begin(); it != forwardNext.end(); it++)
    {
        compositeHistory.push_back(*it);
    }

    return compositeHistory;
};