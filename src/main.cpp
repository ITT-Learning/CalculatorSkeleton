////////////////////////////////////////////////////////////////////////////
/**
 *  @file   main.cpp
 *  @date   Fri April 16 2021
 *  @brief  Entry Point of Calculator
 */
////////////////////////////////////////////////////////////////////////////

#include <cstring>
#include <string>
#include <memory>
#include <set>

#include <ncurses.h>

#include "Calculator.h"
#include "MathExpression.h"
#include "IOperationFactory.h"
#include "FourOperationFactory.h"
#include "Result.h"
#include "CalcHistory.h"
#include "CalcHistoryTraverser.h"
#include "CalculatorIO.h"



void runMainLoop()
{
    std::unique_ptr<IOperationFactory> operationFactory = std::make_unique<FourOperationFactory>();
    Calculator calculator(std::move(operationFactory));
    std::string historyFilePath = std::string(getenv("HOME")) + "/calc/history";
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
        drawInputLineTo(inputWin, "> " + equation);

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

            drawInputLineTo(inputWin, "> " + equation);
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
      
        if (strcmp(equation.c_str(), "quit") == 0 || strcmp(equation.c_str(), "exit") == 0)
        {
            saveHistory(history, historyFilePath);
            break;
        }
        if (strcmp(equation.c_str(), "help") == 0)
        {
            equation = "";
            cursorPos = 0;
            historyTraverser.reset();
            wprintw(outputWin, helpText());
            continue;
        }
        // TODO make the output redraw after exiting
        if (strcmp(equation.c_str(),"history") == 0)
        {
            printFullHistory(history, stdscr);
            wclear(stdscr);
            historyTraverser.reset();
            equation = "";
            cursorPos = 0;
            continue;
        }

        MathExpression expression(equation);
        if (expression.getRawEquation().empty())
        {
            wprintw(outputWin, "No valid command or equation found.\n");
            continue;
        }

        std::set<std::string> emptyVariablesList = expression.needsVariableValues();
        if (!emptyVariablesList.empty())
        {
            for (auto it = emptyVariablesList.cbegin(); it != emptyVariablesList.cend(); it++)
            {
                std::string variablePrompt = "? " + *it + " = ";
                std::string variableString = "";
                int variableCursorPos = 0;
                // print "<variable name> ?= "
                wclear(inputWin);
                wprintw(inputWin, variablePrompt.c_str());

                // read in a number for the value
                do
                {
                    wmove(inputWin, 0, variablePrompt.length() + variableCursorPos);
                    wrefresh(inputWin);
                    input = getch();
                    
                    if (input == KEY_LEFT)
                    {
                        variableCursorPos -= 1;
                        if (variableCursorPos < 0)
                        {
                            variableCursorPos = 0;
                        }
                        continue;
                    }
                    if (input == KEY_RIGHT)
                    {
                        variableCursorPos += 1;
                        if (variableCursorPos > variableString.length())
                        {
                            variableCursorPos = variableString.length();
                        }
                        continue;
                    }

                    if (input != '.' && !isdigit(input) && input != '-')
                    {
                        continue;
                    }

                    variableString = addProcessedInputToAt(input, variableCursorPos, variableString);

                    drawInputLineTo(inputWin, variablePrompt + variableString);
                }
                while (input != '\n' || variableString.empty());

                // assign that value to expression
                expression.setVariableValue(*it, std::stod(variableString));
            }
        }

        Result<double> result = calculator.calculateResult(expression);
        if (!result.isValid())
        {
            wattron(outputWin, A_BOLD);
            wprintw(outputWin, "Error: ");
            wprintw(outputWin, result.getError().c_str());
            wprintw(outputWin, "\n");
            wattroff(outputWin, A_BOLD);
            continue;
        }

        std::string resultString = doubleToString(*(result.consumeResult()));
        wprintw(outputWin, resultString.c_str());
        wprintw(outputWin, " = ");
        wprintw(outputWin, expression.getRawEquation().c_str());
        wprintw(outputWin, "\n");
        history.addEntry(expression.getRawEquation(), resultString);
        historyTraverser.reset();
        equation = "";
        cursorPos = 0;
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