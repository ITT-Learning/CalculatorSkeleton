#include<gtest/gtest.h>
#include<gmock/gmock.h>

#include <memory>

#include "IMathOperation.h"
#include "Addition.h"
#include "Constant.h"

using namespace testing;



TEST(AdditionTests, AddsPositiveNumbers)
{
    std::unique_ptr<Constant> constant_10 = std::make_unique<Constant>(10);
    std::unique_ptr<Constant> constant_15 = std::make_unique<Constant>(15);
    Addition sumOf10And15(std::move(constant_10), std::move(constant_15));
    EXPECT_DOUBLE_EQ(sumOf10And15.calculate(), 25);
};



TEST(AdditionTests, AddsPositiveAndNegativeNumbers)
{
    std::unique_ptr<Constant> constant_N10 = std::make_unique<Constant>(-10);
    std::unique_ptr<Constant> constant_15 = std::make_unique<Constant>(15);
    Addition sumOfN10And15(std::move(constant_N10), std::move(constant_15));
    EXPECT_DOUBLE_EQ(sumOfN10And15.calculate(), 5);
};



TEST(AdditionTests, AddsNegativeNumbers)
{
    std::unique_ptr<Constant> constant_N10 = std::make_unique<Constant>(-10);
    std::unique_ptr<Constant> constant_N15 = std::make_unique<Constant>(-15);
    Addition sumOfN10AndN15(std::move(constant_N10), std::move(constant_N15));
    EXPECT_DOUBLE_EQ(sumOfN10AndN15.calculate(), -25);
};



TEST(AdditionTests, AddsFractionalNumbers)
{
    std::unique_ptr<Constant> constant_1p5 = std::make_unique<Constant>(1.5);
    std::unique_ptr<Constant> constant_1p3 = std::make_unique<Constant>(1.3);
    Addition sumOf1p5And1p3(std::move(constant_1p5), std::move(constant_1p3));
    EXPECT_DOUBLE_EQ(sumOf1p5And1p3.calculate(), 2.8);
};



TEST(AdditionTests, AddsAssociativelyCorrectly)
{
    std::unique_ptr<Constant> constant1_N10 = std::make_unique<Constant>(-10);
    std::unique_ptr<Constant> constant2_N10 = std::make_unique<Constant>(-10);
    std::unique_ptr<Constant> constant1_15 = std::make_unique<Constant>(15);
    std::unique_ptr<Constant> constant2_15 = std::make_unique<Constant>(15);
    Addition sumOfN10And15(std::move(constant1_N10), std::move(constant1_15));
    Addition sumOf15AndN10(std::move(constant2_15), std::move(constant2_N10));
    EXPECT_DOUBLE_EQ(sumOf15AndN10.calculate(), sumOfN10And15.calculate());
};