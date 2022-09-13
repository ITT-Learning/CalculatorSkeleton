////////////////////////////////////////////////////////////////////////////
/**
 *  @file   main.cpp
 *  @date   Fri April 16 2021
 *  @brief  Entry Point of Calculator
 */
////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cctype>
#include <string>
#include <sstream>

#include <ncurses.h>

#include "Calculator.h"
#include "CalcHistory.h"
#include "CalcHistoryTraverser.h"

const int HISTORY_WINDOW_WIDTH = 25;



void printHistory(CalcHistory& history, WINDOW* writeTo)
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
    int cursorPos = 0;

    while (true)
    {
        wrefresh(stdscr);

        wrefresh(outputWin);
        drawHistoryWindow(historyTraverser, historyWin, maxY);
        drawInputLineTo(inputWin, equation);

        int input;
        do
        {
            wmove(inputWin, 0, 2 + cursorPos);
            wrefresh(inputWin);
            input = getch();
            equation = addProcessedInputToAt(input, cursorPos, equation);
            if (input != KEY_UP && input != KEY_DOWN && input != KEY_LEFT && input != KEY_RIGHT && input != '\n')
            {
                historyTraverser.setCurrentInput(equation);
                drawHistoryWindow(historyTraverser, historyWin, maxY);
            }
            if (input == KEY_LEFT)
            {
                cursorPos -= 1;
                if (cursorPos < 0)
                {
                    cursorPos = 0;
                }
                continue;
            }
            if (input == KEY_RIGHT)
            {
                cursorPos += 1;
                if (cursorPos > equation.length())
                {
                    cursorPos = equation.length();
                }
                continue;
            }

            drawInputLineTo(inputWin, equation);
        } while (input != KEY_UP && input != KEY_DOWN && input != '\n');

        if (input == KEY_UP)
        {
            equation = historyTraverser.previous();
            cursorPos = equation.length();
            continue;
        }
        if (input == KEY_DOWN)
        {
            equation = historyTraverser.next();
            cursorPos = equation.length();
            continue;
        }
      
        if (equation.substr(0, 4) == "quit" || equation.substr(0,4) == "exit")
        {
            break;
        }
        if (equation.substr(0,4) == "help")
        {
            equation = "";
            cursorPos = 0;
            historyTraverser.reset();
            wprintw(outputWin, helpText());
            continue;
        }
        // TODO make the output redraw after exiting
        if (equation.substr(0, 7) == "history")
        {
            printHistory(history, stdscr);
            wclear(stdscr);
            historyTraverser.reset();
            equation = "";
            cursorPos = 0;
            continue;
        }

        std::string sanitizedEquation = Calculator::sanitizeString(equation);
        if (sanitizedEquation.empty())
        {
            wprintw(outputWin, "No valid command or equation found.\n");
            continue;
        }
        try
        {
            double result = Calculator::calculate(sanitizedEquation);
            wprintw(outputWin, CalcHistoryPair::doubleToString(result).c_str());
            wprintw(outputWin, " = ");
            wprintw(outputWin, sanitizedEquation.c_str());
            wprintw(outputWin, "\n");
            history.addEntry(sanitizedEquation, result);
            historyTraverser.reset();
            equation = "";
            cursorPos = 0;
        }
        catch(const char* message)
        {
            wattron(outputWin, A_BOLD);
            wprintw(outputWin, "Error: ");
            wprintw(outputWin, message);
            wprintw(outputWin, "\n");
            wattroff(outputWin, A_BOLD);
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