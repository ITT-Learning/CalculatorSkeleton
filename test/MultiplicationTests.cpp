#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <memory>

#include "IMathOperation.h"
#include "Multiplication.h"
#include "Constant.h"

using namespace testing;

class MultiplicationTests : public ::testing::Test {};



TEST_F(MultiplicationTests, MultipliesPositiveNumbers)
{
    std::unique_ptr<Constant> constant_5 = std::make_unique<Constant>(5);
    std::unique_ptr<Constant> constant_4 = std::make_unique<Constant>(4);
    Multiplication productOf5And4(std::move(constant_5), std::move(constant_4));
    EXPECT_DOUBLE_EQ(productOf5And4.calculate(), 20);
};



TEST_F(MultiplicationTests, MultipliesPositiveAndNegativeNumbers)
{
    std::unique_ptr<Constant> constant_5 = std::make_unique<Constant>(5);
    std::unique_ptr<Constant> constant_N4 = std::make_unique<Constant>(-4);
    Multiplication productOf5AndN4(std::move(constant_5), std::move(constant_N4));
    EXPECT_DOUBLE_EQ(productOf5AndN4.calculate(), -20);
};



TEST_F(MultiplicationTests, MultipliesNegativeNumbers)
{
    std::unique_ptr<Constant> constant_N5 = std::make_unique<Constant>(-5);
    std::unique_ptr<Constant> constant_N4 = std::make_unique<Constant>(-4);
    Multiplication productOfN5AndN4(std::move(constant_N5), std::move(constant_N4));
    EXPECT_DOUBLE_EQ(productOfN5AndN4.calculate(), 20);
};



TEST_F(MultiplicationTests, MultipliesFractionalNumbers)
{
    std::unique_ptr<Constant> constant_2p5 = std::make_unique<Constant>(2.5);
    std::unique_ptr<Constant> constant_2 = std::make_unique<Constant>(2);
    Multiplication productOf2p5And2(std::move(constant_2p5), std::move(constant_2));
    EXPECT_DOUBLE_EQ(productOf2p5And2.calculate(), 5);
};



TEST_F(MultiplicationTests, MultipliesAssociativelyCorrectly)
{
    std::unique_ptr<Constant> constant1_N4 = std::make_unique<Constant>(-4);
    std::unique_ptr<Constant> constant2_N4 = std::make_unique<Constant>(-4);
    std::unique_ptr<Constant> constant1_5 = std::make_unique<Constant>(5);
    std::unique_ptr<Constant> constant2_5 = std::make_unique<Constant>(5);
    Multiplication productOfN4And5(std::move(constant1_N4), std::move(constant1_5));
    Multiplication productOf5AndN4(std::move(constant2_5), std::move(constant2_N4));
    EXPECT_DOUBLE_EQ(productOfN4And5.calculate(), productOf5AndN4.calculate());
}