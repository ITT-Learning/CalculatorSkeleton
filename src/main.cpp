////////////////////////////////////////////////////////////////////////////
/**
 *  @file   main.cpp
 *  @date   Fri April 16 2021
 *  @brief  Entry Point of Calculator
 */
////////////////////////////////////////////////////////////////////////////

#include <string>

#include <ncurses.h>

#include "Calculator.h"
#include "CalcHistory.h"
#include "CalcHistoryTraverser.h"
#include "CalculatorIO.h"



void runMainLoop()
{
    std::string historyFilePath = std::string(getenv("HOME")) + "/calc/history.txt";
    CalcHistory history;
    history.initialzeFromFilePath(historyFilePath);
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
            saveHistory(history);
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
            printFullHistory(history, stdscr);
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
    try { runMainLoop(); } catch(...) { /* intentionally empty */ }
    endNcurses();
    return 0;
};