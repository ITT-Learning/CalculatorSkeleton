/**
 * @file OpSymbolGtest.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../inc/OpSymbol.h"

using namespace Calculator;

TEST(Week3OpSymbolTests, OpSymbolIsImplementable)
{
    OpSymbol os("A_SYMBOL", OPORDER::ZERO);

    EXPECT_EQ(os.Id(), "A_SYMBOL");
    EXPECT_EQ(os.Regex(), "A_SYMBOL");
    EXPECT_EQ(os.Order(), OPORDER::ZERO);
}

TEST(Week3OpSymbolTests, EscapedOpSymbolIsImplementable)
{
    OpSymbol os("A_SYMBOL", OPORDER::ZERO, true);

    EXPECT_EQ(os.Id(), "A_SYMBOL");
    EXPECT_EQ(os.Regex(), "\\A_SYMBOL");
    EXPECT_EQ(os.Order(), OPORDER::ZERO);
}
  