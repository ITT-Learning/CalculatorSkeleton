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

int findPrecisionFor(int number, int decimalDigits = 4)
{
    int baseLog = (int)log10(std::abs(number));
    int effectiveLog = std::max(baseLog + 1 + decimalDigits, baseLog * - 1);
    return effectiveLog;
};

void printHistory(const CalcHistory history, WINDOW* writeTo)
{
    wprintw(writeTo, "\n\n");
    wprintw(writeTo, CalcHistory::toString(history).c_str());
};

const char* helpText()
{
    return "\n\n           Calculator\n\n      supports + - * / ( )\n    enter history for history\n       enter quit to quit\n  enter help for this dialogue\n\n";
};

std::string addProcessedInputTo(char input, const std::string &baseString = "")
{
    std::string workingString = baseString;
    if(isdigit(input) || input == '.' || input == '+' || input == '-' || input == '*' || input == '/' || input == '(' || input ==')' || isalpha(input))
    {
        // wprintw(writeTo, std::string(1, input).c_str());
        // wrefresh(writeTo);
        workingString += input;
    }
    if(input == 7 && workingString.length() > 0)
    {
        // wprintw(writeTo, "\b \b");
        // wrefresh(writeTo);
        workingString = workingString.substr(0, workingString.length() - 1);
    }
    return workingString;
};

WINDOW* createBoxedWin(int height, int width, int starty, int startx)
{
    WINDOW* localWin;
	localWin = newwin(height, width, starty, startx);
	box(localWin, 0, 0);
	wrefresh(localWin);
	return localWin;
};

void drawInputLineTo(WINDOW* inputWin, std::string str)
{
    wclear(inputWin);
    wprintw(inputWin, "> ");
    wprintw(inputWin, str.c_str());
    wrefresh(inputWin);
};

void repl()
{
    CalcHistory history;
    CalcHistoryTraverser historyTraverser(&history);
    std::string equation = "";
    WINDOW* outputWin;
    WINDOW* inputWin;
    int maxX, maxY;
    getmaxyx(stdscr, maxY, maxX);
    outputWin = newwin(maxY - 1, maxX, 0, 0);
    inputWin = newwin(1, maxX, maxY - 1, 0);
    scrollok(outputWin, true);
    wmove(outputWin, maxY - 8, 0);
    wprintw(outputWin, helpText());
    wscrl(outputWin, 1);
    while(true)
    {
        move(maxY, maxX + 2 + equation.length());
        wrefresh(stdscr);

        wrefresh(outputWin);
        drawInputLineTo(inputWin, equation);

        char input;
        do
        {
            input = getch();
            equation = addProcessedInputTo(input, equation);
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
        
        // drawInputLineTo(inputWin, equation);

        // equation = getSanitizedLine(equation, inputWin);
        if(equation.substr(0, 4) == "quit" || equation.substr(0,4) == "exit")
            break;
        if(equation.substr(0,4) == "help")
        {
            equation = "";
            wprintw(outputWin, helpText());
            continue;
        }
        if(equation.substr(0, 7) == "history")
        {
            printHistory(history, outputWin);
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
    // showHelpText();
    try { repl(); } catch(...) { /* intentionally empty */ }
    endNcurses();
    return 0;
};