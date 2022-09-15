#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <cmath>
#include <memory>

#include "IMathOperation.h"
#include "Division.h"
#include "Constant.h"

using namespace testing;

class DivisionTests : public ::testing::Test {};

TEST_F(DivisionTests, DividesPositiveNumbers)
{
    std::unique_ptr<Constant> constant_20 = std::make_unique<Constant>(20);
    std::unique_ptr<Constant> constant_4 = std::make_unique<Constant>(4);
    Division quotientOf20And4(std::move(constant_20), std::move(constant_4));
    EXPECT_DOUBLE_EQ(quotientOf20And4.calculate(), 5);
};



TEST_F(DivisionTests, DividesPositiveAndNegativeNumbers)
{
    std::unique_ptr<Constant> constant_N20 = std::make_unique<Constant>(-20);
    std::unique_ptr<Constant> constant_4 = std::make_unique<Constant>(4);
    Division quotientOfN20And4(std::move(constant_N20), std::move(constant_4));
    EXPECT_DOUBLE_EQ(quotientOfN20And4.calculate(), -5);
};



TEST_F(DivisionTests, DividesNegativeNumbers)
{
    std::unique_ptr<Constant> constant_N20 = std::make_unique<Constant>(-20);
    std::unique_ptr<Constant> constant_N4 = std::make_unique<Constant>(-4);
    Division quotientOfN20AndN4(std::move(constant_N20), std::move(constant_N4));
    EXPECT_DOUBLE_EQ(quotientOfN20AndN4.calculate(), 5);
};



TEST_F(DivisionTests, DividesDecimals)
{
    std::unique_ptr<Constant> constant_1p5 = std::make_unique<Constant>(1.5);
    std::unique_ptr<Constant> constant_0p5 = std::make_unique<Constant>(0.5);
    Division quotientOf1p5And0p5(std::move(constant_1p5), std::move(constant_0p5));
    EXPECT_DOUBLE_EQ(quotientOf1p5And0p5.calculate(), 3);
};



TEST_F(DivisionTests, DividesAssociativelyCorrectly)
{
    std::unique_ptr<Constant> constant1_20 = std::make_unique<Constant>(20);
    std::unique_ptr<Constant> constant2_20 = std::make_unique<Constant>(20);
    std::unique_ptr<Constant> constant1_4= std::make_unique<Constant>(4);
    std::unique_ptr<Constant> constant2_4 = std::make_unique<Constant>(4);
    Division quotientOf20And4(std::move(constant1_20), std::move(constant1_4));
    Division quotientOf4And20(std::move(constant2_4), std::move(constant2_20));
    EXPECT_DOUBLE_EQ(quotientOf20And4.calculate(), 5);
    EXPECT_DOUBLE_EQ(quotientOf4And20.calculate(), 0.2);
};



TEST_F(DivisionTests, ReturnsNanOnDivideByZero)
{
    std::unique_ptr<Constant> constant1 = std::make_unique<Constant>(1);
    std::unique_ptr<Constant> constant0 = std::make_unique<Constant>(0);
    Division DivideByZero(std::move(constant1), std::move(constant0));
    EXPECT_TRUE(std::isnan(DivideByZero.calculate()));
};