#ifndef CALCULATOR_IO_H
#define CALCULATOR_IO_H

#include <cctype>
#include <string>

#include <ncurses.h>
#include "CalcHistory.h"
#include "CalcHistoryTraverser.h"


const int HISTORY_WINDOW_WIDTH = 25;



void printFullHistory(CalcHistory& history, WINDOW* writeTo)
{
    int maxX = getmaxx(writeTo);
    int maxY = getmaxy(writeTo);
    CalcHistoryTraverser historyTraverser(&history);
    int input = 0;
    do
    {

        if (input == KEY_UP)
        {
            historyTraverser.previous();
        }
        if (input == KEY_DOWN)
        {
            historyTraverser.next();
        }
        wclear(writeTo);
        std::vector<std::string> historyEntries = historyTraverser.getHistoryStringWithBoundsAndResults(maxY - 2, 0, maxX);
        for (std::vector<std::string>::iterator it = historyEntries.begin(); it != historyEntries.end(); it++)
        {
            wprintw(writeTo, it->c_str());
            if (it->length() < maxX)
            {
                wprintw(writeTo, "\n");
            }
        }
        wprintw(writeTo, "<Press enter to return>");
        wrefresh(writeTo);
        input = getch();
    } while (input != '\n');
};



const char* helpText()
{
    return "\n\n           Calculator\n\n      supports + - * / ( )\n    enter history for history\n       enter quit to quit\n  enter help for this dialogue\n\n";
};



std::string addProcessedInputToAt(char input, int& cursorPos, const std::string &baseString = "")
{
    std::string workingString = baseString;
    if (isdigit(input) || input == '.' || input == '+' || input == '-' || input == '*' || input == '/' || input == '(' || input ==')' || isalpha(input))
    {
        if (cursorPos == workingString.length())
        {
            workingString += input;
        }
        else
        {
            workingString.replace(cursorPos, 1, std::string(1, input));
        }
        cursorPos += 1;
    }
    if (input == 7 && workingString.length() > 0)
    {
        if (cursorPos > 0)
        {
            workingString.replace(cursorPos - 1, 1, "");
        }
        cursorPos -= 1;
        if (cursorPos < 0)
        {
            cursorPos = 0;
        }
    }
    return workingString;
};



void drawInputLineTo(WINDOW* inputWin, std::string str)
{
    wclear(inputWin);
    wprintw(inputWin, "> ");
    wprintw(inputWin, str.c_str());
    wrefresh(inputWin);
};



void drawHistoryWindow(CalcHistoryTraverser &historyTraverser, WINDOW* historyWin, int height)
{
    wclear(historyWin);
    std::vector<std::string> historyEntries = historyTraverser.getHistoryStringWithBounds((height - 1) / 2, (height - 1) / 2, HISTORY_WINDOW_WIDTH);
    for (std::vector<std::string>::iterator it = historyEntries.begin(); it != historyEntries.end(); it++)
    {
        if (it == historyEntries.begin() + ((height - 1) / 2))
        {
            wattron(historyWin, A_STANDOUT);
        }
        std::string lineOutput = *it;
        if (lineOutput.length() < HISTORY_WINDOW_WIDTH)
        {
            lineOutput += std::string(HISTORY_WINDOW_WIDTH - lineOutput.length(), ' ');
        }
        wprintw(historyWin, lineOutput.c_str());
        if (it == historyEntries.begin() + ((height - 1) / 2))
        {
            wattroff(historyWin, A_STANDOUT);
        }
    }
    wrefresh(historyWin);
};




void saveHistory(const CalcHistory& history)
{
    std::string historyFilePath = std::string(getenv("HOME")) + "/calc/history.txt";
    history.saveToFilePath(historyFilePath);
};

#endif
