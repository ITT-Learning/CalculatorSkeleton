
////////////////////////////////////////////////////////////////////////////
/**
 *  @file   CalculatorApplication.cpp
 *  @date   Fri April 16 2021
 *  @brief  Definitions for Calculator Application
 */
////////////////////////////////////////////////////////////////////////////

#include "CalculatorApplication.h"

#include <algorithm>
#include <cmath>
#include <fstream>
#include <future>
#include <iostream>

#include "flatbuffers/flatbuffers.h"

#include "CalculatorStrings.h"
#include "Color.h"
#include "CompoundExpressionCalculator.h"
#include "CustomCalculatorFactory.h"
#include "History.h"
#include "SimpleExpressionCalculatorFactory.h"

namespace calculator
{
    //place to test stuff please ignore
    void CalculatorApplication::playground()
    {
    }

    void CalculatorApplication::run()
    {
        runW6();
    }

    void CalculatorApplication::runW3()
    {
        calculator::SimpleExpressionCalculatorFactory calculatorFactory;
        while (true)
        {
            std::cout << calculator::CalculatorStrings::W2_MAIN_PROMPT << std::endl;
            std::string exit = CalculatorStrings::EXIT_PROMPT;
            std::cout << Color::sub(exit) << std::endl;

            std::string input;
            getline(std::cin, input);

            if(isExitString(input))
            {
                break;
            }

            auto calculator = calculatorFactory.createCalculator(input);
            if(calculator)
            {
                std::string calcOutput = calculator->toString();
                std::cout << Color::message(calcOutput) << std::endl;

                History::getInstance()->appendCalculator(*calculator);
            }
            else
            {
                std::string error = std::string(calculator::CalculatorStrings::ERROR_MESSAGE) + calculator::CalculatorStrings::ERROR_MESSAGE_INVALID_INPUT;
                std::cout << Color::error(error) << std::endl;
            }
        }
    }

    void CalculatorApplication::runW4()
    {
        //loop through to check which equation
        inputLoop(CalculatorStrings::W4_MAIN_PROMPT, [](const std::string& input)
        {
            if (input.size() == 1)
            {
                //double looping for the equation
                switch (input[0])
                {
                    case (int)Options::FIRST:
                    {
                        //sqrt
                        inputLoop(CalculatorStrings::W4_SQRT_PROMPT, [](const std::string &input) {
                            CustomCalculatorFactory<double> calculatorFactory(
                                    [](auto terms) { return std::sqrt(terms[0]); }, CalculatorStrings::W4_SQRT_FORMAT);
                            auto calculator = calculatorFactory.createCalculator(input);
                            std::cout << calculator->toString() << std::endl;
                        });
                        break;
                    }
                    case (int)Options::SECOND:
                    {
                        //quadratic formula
                        inputLoop(CalculatorStrings::W4_QUAD_PROMPT, [](const std::string &input) {
                            CustomCalculatorFactory<double> calculatorFactory([](auto terms) {
                                return -terms[1] +
                                       std::sqrt(terms[1] * terms[1] - 4 * terms[0] * terms[2]) / 2 * terms[0];
                            }, CalculatorStrings::W4_QUAD_FORMAT);
                            auto calculator = calculatorFactory.createCalculator(input);
                            std::cout << calculator->toString() << std::endl;
                        });
                        break;
                    }
                    case (int)Options::THIRD:
                    {
                        //pythagorean theorem
                        inputLoop(CalculatorStrings::W4_PYTH_PROMPT, [](const std::string &input) {
                            CustomCalculatorFactory<double> calculatorFactory([](auto terms) {
                                return std::sqrt(terms[0] * terms[0] + terms[1] * terms[1]);
                            }, CalculatorStrings::W4_PYTH_FORMAT);
                            auto calculator = calculatorFactory.createCalculator(input);
                            std::cout << calculator->toString() << std::endl;
                        });
                        break;
                    }
                    case (int)Options::FOURTH:
                    {
                        //add
                        inputLoop(CalculatorStrings::W4_ADD2_PROMPT, [](const std::string &input) {
                            CustomCalculatorFactory<double> calculatorFactory([](auto terms) {
                                return terms[0] + terms[1];
                            }, CalculatorStrings::W4_ADD2_FORMAT);
                            auto calculator = calculatorFactory.createCalculator(input);
                            std::cout << calculator->toString() << std::endl;
                        });
                        break;
                    }
                    default:
                    {
                        //do nothing, inputLoop will loop if input is invalid
                        break;
                    }
                }
            }
        });
    }

    void CalculatorApplication::runW5()
    {
        inputLoop(CalculatorStrings::W5_MAIN_PROMPT,
                  [](auto input){
                      if (input.size() == 1)
                      {
                          switch (input[0])
                          {
                              case (int)Options::FIRST:
                              {
                                  inputLoop(CalculatorStrings::W5_COMPOUND_PROMPT, [](auto input) {
                                      CompoundExpressionCalculator compoundCalc{input};
                                      std::string calcOutput = compoundCalc.toString();
                                      std::cout << Color::message(calcOutput) << std::endl;
                                      History::getInstance()->appendCalculator(compoundCalc);
                                  });
                                  break;
                              }
                              case (int)Options::SECOND:
                              {
                                  inputLoop(CalculatorStrings::W5_VARIABLE_PROMPT, [](auto input) {
                                      auto vars = input;

                                      std::string prompt =
                                              std::string(CalculatorStrings::W5_VARCOMP_PROMPT) + Color::info(input);

                                      inputLoop(prompt, [&](auto input) {
                                          auto variables = CompoundExpressionCalculator::toVariableMap(vars);
                                          CompoundExpressionCalculator compoundCalc{variables, input};
                                          std::string calcOutput = compoundCalc.toString();
                                          std::cout << Color::message(calcOutput) << std::endl;
                                          History::getInstance()->appendCalculator(compoundCalc);
                                      });
                                  });
                                  break;
                              }
                          }
                      }
        });
    }

    void CalculatorApplication::runW6()
    {
        inputLoop(CalculatorStrings::W6_MAIN_PROMPT
                  , [](auto input)
                  {
                    if (input.size() == 1)
                    {
                        switch (input[0])
                        {
                            case (int)Options::FIRST:
                            {
                                runW3();
                                break;
                            }
                            case (int)Options::SECOND:
                            {
                                runW5();
                                break;
                            }
                            case (int)Options::THIRD:
                            {
                                history();
                                break;
                            }
                        }
                    }
        });
    }

    void CalculatorApplication::inputLoop(const std::string& prompt, const std::function<void(const std::string&)>& function)
    {
        while(true)
        {
            std::cout << prompt << std::endl;
            std::string exit = CalculatorStrings::EXIT_PROMPT;
            std::cout << Color::sub(exit) << std::endl;
            std::string input;
            std::getline(std::cin, input);
            if(isExitString(input))
            {
                break;
            }

            function(input);
        }
    }

    void CalculatorApplication::history()
    {
        auto &history = History::getInstance()->getBuiltHistory()->list;
        if(history.empty())
        {
            std::string historyError = CalculatorStrings::NO_HISTORY;
            std::cout << Color::error(historyError) << std::endl;
        }
        else
        {
            int location = history.size() - 1;
            std::string locationString = CalculatorStrings::BRACKET_OPEN + std::to_string(location) + CalculatorStrings::BRACKET_CLOSE + CalculatorStrings::SPACE;
            std::cout << Color::info(locationString) << Color::message(history.at(location)->full_equation) << std::endl;
            inputLoop(CalculatorStrings::W6_HISTORY_PROMPT, [&history, &location](auto input) {
                if (isalpha(input[0]))
                {
                    switch (tolower(input[0]))
                    {
                        case (int)Options::UP:
                        {
                            //move negatively through the history, clamped at 0
                            location = std::max(0, location - 1);
                            break;
                        }
                        case (int)Options::DOWN:
                        {
                            //move positively through the history, clamped at last history index
                            location = std::min(static_cast<int>(history.size() - 1), location + 1);
                            break;
                        }
                        default:
                        {
                            //do nothing else
                            break;
                        }
                    }
                }
                else
                {
                    //move a number into the index
                    int index = location;
                    std::stringstream stream(input);
                    stream >> index;
                    //clamp between 0 and top index
                    location = std::max(std::min(index, static_cast<int>(history.size()) - 1), 0);
                }

                std::string locationString = CalculatorStrings::BRACKET_OPEN + std::to_string(location) + CalculatorStrings::BRACKET_CLOSE + CalculatorStrings::SPACE;
                std::cout << Color::info(locationString) << Color::message(history.at(location)->full_equation) << std::endl;
            });
        }
    }

    bool CalculatorApplication::isExitString(const std::string& input)
    {
        std::string lcInput = input;
        std::transform(lcInput.begin(), lcInput.end(), lcInput.begin(), [](unsigned char c){return std::tolower(c); });
        return (lcInput == CalculatorStrings::EXIT_1 ||
                lcInput == CalculatorStrings::EXIT_2 ||
                lcInput == CalculatorStrings::EXIT_3 ||
                lcInput == CalculatorStrings::EXIT_4);
    }
}