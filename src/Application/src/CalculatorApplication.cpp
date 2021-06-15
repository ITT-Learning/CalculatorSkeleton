
////////////////////////////////////////////////////////////////////////////
/**
 *  @file   CalculatorApplication.cpp
 *  @date   Fri April 16 2021
 *  @brief  Definitions for Calculator Application
 */
////////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include <cmath>
#include <iostream>
#include <regex>
#include <thread>
#include <future>

#include "CalculatorApplication.h"
#include "CalculatorStrings.h"
#include "CustomCalculatorFactory.h"
#include "SimpleExpressionCalculatorFactory.h"
#include "CompoundExpressionCalculator.h"

namespace calculator
{
    void CalculatorApplication::run()
    {
        runW5();
    }

    void CalculatorApplication::runW3()
    {
        calculator::SimpleExpressionCalculatorFactory calculatorFactory;
        while (true)
        {
            std::cout << calculator::CalculatorStrings::W2_MAIN_PROMPT << std::endl;

            std::string input;
            getline(std::cin, input);

            if(input == calculator::CalculatorStrings::EXIT_3)
            {
                break;
            }

            auto calculator = calculatorFactory.createCalculator(input);
            if(calculator)
            {
                std::cout << calculator->toString() << std::endl;
            }
            else
            {
                std::cout << calculator::CalculatorStrings::ERROR_MESSAGE << calculator::CalculatorStrings::ERROR_MESSAGE_INVALID_INPUT << std::endl;
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
                    case '1': //sqrt
                        inputLoop(CalculatorStrings::W4_SQRT_PROMPT, [](const std::string& input)
                        {
                            CustomCalculatorFactory<double> calculatorFactory([](auto terms){ return std::sqrt(terms[0]);}, CalculatorStrings::W4_SQRT_FORMAT);
                            auto calculator = calculatorFactory.createCalculator(input);
                            std::cout << calculator->toString() << std::endl;
                        });
                        break;
                    case '2': //quadratic formula
                        inputLoop(CalculatorStrings::W4_QUAD_PROMPT, [](const std::string& input)
                        {
                            CustomCalculatorFactory<double> calculatorFactory([](auto terms)
                            {
                                return -terms[1] + std::sqrt(terms[1] * terms[1] - 4 * terms[0] * terms[2]) / 2 * terms[0];
                            }, CalculatorStrings::W4_QUAD_FORMAT);
                            auto calculator = calculatorFactory.createCalculator(input);
                            std::cout << calculator->toString() << std::endl;
                        });
                        break;
                    case '3': //pythagorean theorem
                        inputLoop(CalculatorStrings::W4_PYTH_PROMPT, [](const std::string& input)
                        {
                            CustomCalculatorFactory<double> calculatorFactory([](auto terms)
                                                                              {
                                                                                  return std::sqrt(terms[0] * terms[0] + terms[1] * terms[1]);
                                                                              }, CalculatorStrings::W4_PYTH_FORMAT);
                            auto calculator = calculatorFactory.createCalculator(input);
                            std::cout << calculator->toString() << std::endl;
                        });
                        break;
                    case '4': //add
                        inputLoop(CalculatorStrings::W4_ADD2_PROMPT, [](const std::string& input)
                        {
                            CustomCalculatorFactory<double> calculatorFactory([](auto terms)
                                                                              {
                                                                                  return terms[0] + terms[1];
                                                                              }, CalculatorStrings::W4_ADD2_FORMAT);
                            auto calculator = calculatorFactory.createCalculator(input);
                            std::cout << calculator->toString() << std::endl;
                        });
                        break;
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
                              case '1':
                                  inputLoop(CalculatorStrings::W5_COMPOUND_PROMPT, [](auto input){
                                      CompoundExpressionCalculator compoundCalc{input};
                                      std::cout << compoundCalc.toString() << std::endl;
                                  });
                                  break;
                              case '2':
                                  inputLoop(CalculatorStrings::W5_VARIABLE_PROMPT, [](auto input){
                                      auto vars = input;

                                      std::string prompt = std::string(CalculatorStrings::W5_VARCOMP_PROMPT) + input;

                                      inputLoop(prompt, [&](auto input){
                                          auto variables = CompoundExpressionCalculator::toVariableMap(vars);
                                          CompoundExpressionCalculator compoundCalc{variables, input};
                                          std::cout << compoundCalc.toString() << std::endl;
                                      });
                                  });
                                  break;
                          }
                      }
        });
    }

    //place to test stuff please ignore
    void CalculatorApplication::playground()
    {

        auto map = CompoundExpressionCalculator::toVariableMap("a = 10, b = 100, c = 1000, f = 8394");
        std::cout << map.at('a') << std::endl;

        CompoundExpressionCalculator cec{map, "abc"};

        CompoundExpressionCalculator c{"10 + 10 - 100 839 djfkla"};

        std::cout << cec.toString() << std::endl;
    }

    void CalculatorApplication::inputLoop(const std::string& prompt, const std::function<void(const std::string&)>& function)
    {
        while(true)
        {
            std::cout << prompt << std::endl;
            std::cout << CalculatorStrings::EXIT_PROMPT << std::endl;
            std::string input;
            std::getline(std::cin, input);
            std::string lcInput = input;
            std::transform(lcInput.begin(), lcInput.end(), lcInput.begin(), [](unsigned char c){return std::tolower(c); });
            if(lcInput == CalculatorStrings::EXIT_1 ||
               lcInput == CalculatorStrings::EXIT_2 ||
               lcInput == CalculatorStrings::EXIT_3 ||
               lcInput == CalculatorStrings::EXIT_4)
            {
                break;
            }
            function(input);
        }
    }
}