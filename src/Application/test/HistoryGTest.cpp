///////////////////////////////////////////////////
/**
 * @file HistoryGTest.cpp
 * @brief Unit tests for History
 */
///////////////////////////////////////////////////


#include <cstdint>
#include <fstream>
#include <iostream>

#include<gtest/gtest.h>
#include<gmock/gmock.h>

#include "History.h"
#include "CalculatorApplication.h"
#include "CalculatorApplicationFactory.h"
#include "CalculatorStrings.h"

using namespace calculator;
using namespace testing;

/**
 * @brief Unit test to make sure History::clear method points works
 * 
 */
TEST(whenTestingHistory, WhenCallingHistoryClearMethod_ThenCorrectVectorSizeReturn)
{
    History::getInstance()->clear();
    int historyStored = History::getInstance()->getSize();
    EXPECT_EQ(0, historyStored);
}

/**
 * @brief Unit test to make sure History::appendCalculator method points works
 * 
 */
TEST(whenTestingHistory, WhenCallingHistoryAppendCalculatorMethod_ThenCorrectValuesPlacedInVector)
{
    History::getInstance()->appendCalculator(15, "5 * 3");
    int calculatorVectorSize = History::getInstance()->getSize();
    EXPECT_EQ(1, calculatorVectorSize);
}

/**
 * @brief Unit test to make sure History::GetBuiltHistory method points works
 * 
 */
TEST(whenTestingHistory, WhenCallingHistoryGetBuiltHistoryMethod_ThenCorrectValuesPlacedInVector)
{
    std::string originalEquation_="";
    int answer_ = 0;
    History::getInstance()->clear();
    History::getInstance()->appendCalculator(15, "5 * 3");
    auto &history = History::getInstance()->getBuiltHistory()->list;
    int calculatorVectorSize = History::getInstance()->getSize();
    for(int i = 0; i < calculatorVectorSize; i++)
    {
        originalEquation_ = history.at(i)->originalEquation;
        answer_ = history.at(i)->answer;
    }
    EXPECT_EQ(1, calculatorVectorSize);
    EXPECT_FLOAT_EQ(15, answer_);
    EXPECT_EQ("5 * 3", originalEquation_);
}