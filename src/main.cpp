////////////////////////////////////////////////////////////////////////////
/**
 *  @file   main.cpp
 *  @date   Fri April 16 2021
 *  @brief  Entry Point of Calculator
 */
////////////////////////////////////////////////////////////////////////////

#include "Calculator.h"
#include "CalcHistory.h"
#include "CalcHistoryTraverser.h"
#include <iostream>
#include <string>
#include <math.h>
#include <ncurses.h>
#include <cctype>

const int HISTORY_WINDOW_WIDTH = 25;

int findPrecisionFor(int number, int decimalDigits = 4)
{
    int baseLog = (int)log10(std::abs(number));
    int effectiveLog = std::max(baseLog + 1 + decimalDigits, baseLog * - 1);
    return effectiveLog;
};

//TODO save history before this
void printHistory(CalcHistory& history, WINDOW* writeTo)
{
    int maxX = getmaxx(writeTo);
    int maxY = getmaxy(writeTo);
    CalcHistoryTraverser historyTraverser(&history);
    int input = 0;
    do
    {

        if(input == KEY_UP)
            historyTraverser.previous();
        if(input == KEY_DOWN)
            historyTraverser.next();
        wclear(writeTo);
        std::vector<std::string> historyEntries = historyTraverser.getHistoryStringWithBoundsAndResults(maxY - 2, 0, maxX);
        for(std::vector<std::string>::iterator it = historyEntries.begin(); it != historyEntries.end(); it++)
        {
            wprintw(writeTo, it->c_str());
            if(it->length() < maxX)
                wprintw(writeTo, "\n");
        }
        wprintw(writeTo, "<Press enter to return>");
        wrefresh(writeTo);
        input = getch();
    } while(input != '\n');
};

const char* helpText()
{
    return "\n\n           Calculator\n\n      supports + - * / ( )\n    enter history for history\n       enter quit to quit\n  enter help for this dialogue\n\n";
};

//TODO add cursor positioning support
std::string addProcessedInputTo(char input, const std::string &baseString = "")
{
    std::string workingString = baseString;
    if(isdigit(input) || input == '.' || input == '+' || input == '-' || input == '*' || input == '/' || input == '(' || input ==')' || isalpha(input))
    {
        workingString += input;
    }
    if(input == 7 && workingString.length() > 0)
    {
        workingString = workingString.substr(0, workingString.length() - 1);
    }
    return workingString;
};

// REVIEW remove this?
// WINDOW* createBoxedWin(int height, int width, int starty, int startx)
// {
//     WINDOW* localWin;
// 	localWin = newwin(height, width, starty, startx);
// 	box(localWin, 0, 0);
// 	wrefresh(localWin);
// 	return localWin;
// };

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
    for(std::vector<std::string>::iterator it = historyEntries.begin(); it != historyEntries.end(); it++)
    {
        if(it == historyEntries.begin() + ((height - 1) / 2))
            wattron(historyWin, A_BOLD);
        wprintw(historyWin, it->c_str());
        if(it->length() < HISTORY_WINDOW_WIDTH)
            wprintw(historyWin, "\n");
        if(it == historyEntries.begin() + ((height - 1) / 2))
            wattroff(historyWin, A_BOLD);
    }
    wrefresh(historyWin);
}

void repl()
{
    CalcHistory history;
    CalcHistoryTraverser historyTraverser(&history);
    std::string equation = "";

    WINDOW* outputWin;
    WINDOW* inputWin;
    WINDOW* historyWin;
    int maxX, maxY;
    getmaxyx(stdscr, maxY, maxX);
    outputWin = newwin(maxY - 1, maxX - HISTORY_WINDOW_WIDTH, 0, 0);
    scrollok(outputWin, true);
    inputWin = newwin(1, maxX - HISTORY_WINDOW_WIDTH, maxY - 1, 0);
    historyWin = newwin(maxY, HISTORY_WINDOW_WIDTH, 0, maxX - HISTORY_WINDOW_WIDTH);

    wmove(outputWin, maxY - 8, 0);
    wprintw(outputWin, helpText());
    wscrl(outputWin, 1);

    while(true)
    {
        move(maxY, maxX + 2 + equation.length());
        wrefresh(stdscr);

        wrefresh(outputWin);
        drawHistoryWindow(historyTraverser, historyWin, maxY);
        drawInputLineTo(inputWin, equation);

        char input;
        do
        {
            input = getch();
            equation = addProcessedInputTo(input, equation);
            if(input != 3 && input != 2 && input != '\n')
            {
                historyTraverser.setCurrentInput(equation);
                drawHistoryWindow(historyTraverser, historyWin, maxY);
            }
            drawInputLineTo(inputWin, equation);
        } while (input != 3 && input != 2 && input != '\n');

        if(input == 3)
        {
            equation = historyTraverser.previous();
            continue;
        }
        if(input == 2)
        {
            equation = historyTraverser.next();
            continue;
        }

        if(equation.substr(0, 4) == "quit" || equation.substr(0,4) == "exit")
            break;
        if(equation.substr(0,4) == "help")
        {
            equation = "";
            historyTraverser.reset();
            wprintw(outputWin, helpText());
            continue;
        }
        if(equation.substr(0, 7) == "history")
        {
            printHistory(history, stdscr);
            wclear(stdscr);
            historyTraverser.reset();
            equation = "";
            continue;
        }

        equation = Calculator::sanitizeString(equation);
        if(equation.empty())
        {
            wprintw(outputWin, "No valid command or equation found.\n");

            continue;
        }
        try
        {
            double result = Calculator::calculate(equation);
            // std::cout.precision(findPrecisionFor(result)); TODO fix this for ncurses
            wprintw(outputWin, std::to_string(result).c_str());
            wprintw(outputWin, " = ");
            wprintw(outputWin, equation.c_str());
            wprintw(outputWin, "\n");
            history.addEntry(equation, result);
            historyTraverser.reset();
            equation = "";
        }
        catch(const char* message)
        {
            wprintw(outputWin, "\nError: ");
            wprintw(outputWin, message);
            wprintw(outputWin, "\n");
        }
    }
};

void initNcurses()
{
    initscr();
    noecho();
    keypad(stdscr, true);
};

void endNcurses()
{
    endwin();
};

int main(int argc, char* argv[]) 
{
    initNcurses();
    try { repl(); } catch(...) { /* intentionally empty */ }
    endNcurses();
    return 0;
};