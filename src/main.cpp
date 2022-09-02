////////////////////////////////////////////////////////////////////////////
/**
 *  @file   main.cpp
 *  @date   Fri April 16 2021
 *  @brief  Entry Point of Calculator
 */
////////////////////////////////////////////////////////////////////////////

#include "Calculator.h"
#include "CalcHistory.h"
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

void printHistory(const CalcHistory history)
{
    printw("\n\n");
    printw(CalcHistory::toString(history).c_str());
    printw("\n\n");
};

const char* helpText()
{
    return "\n\n           Calculator\n\n      supports + - * / ( )\n    enter history for history\n       enter quit to quit\n  enter help for this dialogue\n\n";
};

std::string getSanitizedLine(const std::string &baseString = "", WINDOW* writeTo = stdscr)
{
    std::string workingString = baseString;
    char input;
    do
    {
        input = getch();
        if(isdigit(input) || input == '.' || input == '+' || input == '-' || input == '*' || input == '/' || input == '(' || input ==')' || isalpha(input))
        {
            wprintw(writeTo, std::string(1, input).c_str());
            wrefresh(writeTo);
            workingString += input;
        }
        if(input == 7 && workingString.length() > 0)
        {
            wprintw(writeTo, "\b \b");
            wrefresh(writeTo);
            workingString = workingString.substr(0, workingString.length() - 1);
        }
    } while(input != '\n');
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

void repl()
{
    CalcHistory history;
    std::string equation = "";
    WINDOW* outputWin;
    WINDOW* inputWin;
    int maxX, maxY;
    getmaxyx(stdscr, maxY, maxX);
    outputWin = createBoxedWin(maxY - 2, maxX, 0, 0);
    inputWin = newwin(1, maxX, maxY - 1, 0);
    while(true)
    {
        mvwprintw(inputWin, 0, 0, "> ");
        wprintw(inputWin, equation.c_str());
        wrefresh(inputWin);
        // move(maxY, maxX + 2 + equation.length());
        // wrefresh(stdscr);
        equation = getSanitizedLine(equation, inputWin);
        // getline(std::cin, equation);
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
            printHistory(history);
            equation = "";
            continue;
        }
        equation = Calculator::sanitizeString(equation);
        if(equation.empty())
        {
            printw("\n\nNo valid command or equation found.\n\n");
            continue;
        }
        try
        {
            double result = Calculator::calculate(equation);
            // std::cout.precision(findPrecisionFor(result)); TODO fix this for ncurses
            wprintw(outputWin, "\n= ");
            wprintw(outputWin, std::to_string(result).c_str());
            wprintw(outputWin, "\n\n");
            history.addEntry(equation, result);
            equation = "";
        }
        catch(const char* message)
        {
            printw("\nError: ");
            printw(message);
            printw("\n\n");
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