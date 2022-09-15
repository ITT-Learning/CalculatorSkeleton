#include<gtest/gtest.h>
#include<gmock/gmock.h>

#include <memory>

#include "IMathOperation.h"
#include "Subtraction.h"
#include "Constant.h"

using namespace testing;



TEST(SubtractionTests, SubtractsPositiveNumbers)
{
    std::unique_ptr<Constant> constant_15 = std::make_unique<Constant>(15);
    std::unique_ptr<Constant> constant_10 = std::make_unique<Constant>(10);
    Subtraction diffOf10And15(std::move(constant_15), std::move(constant_10));
    EXPECT_DOUBLE_EQ(diffOf10And15.calculate(), 5);
};



TEST(SubtractionTests, SubtractsPositiveAndNegativeNumbers)
{
    std::unique_ptr<Constant> constant_15 = std::make_unique<Constant>(15);
    std::unique_ptr<Constant> constant_N10 = std::make_unique<Constant>(-10);
    Subtraction diffOfN10And15(std::move(constant_15), std::move(constant_N10));
    EXPECT_DOUBLE_EQ(diffOfN10And15.calculate(), 25);
};



TEST(SubtractionTests, SubtractsNegativeNumbers)
{
    std::unique_ptr<Constant> constant_N10 = std::make_unique<Constant>(-10);
    std::unique_ptr<Constant> constant_N15 = std::make_unique<Constant>(-15);
    Subtraction diffOfN10AndN15(std::move(constant_N10), std::move(constant_N15));
    EXPECT_DOUBLE_EQ(diffOfN10AndN15.calculate(), 5);
};



TEST(SubtractionTests, SubtractsFractionalNumbers)
{
    std::unique_ptr<Constant> constant_1p5 = std::make_unique<Constant>(1.5);
    std::unique_ptr<Constant> constant_1p3 = std::make_unique<Constant>(1.3);
    Subtraction diffOf1p5And1p3(std::move(constant_1p5), std::move(constant_1p3));
    EXPECT_DOUBLE_EQ(diffOf1p5And1p3.calculate(), 0.2);
};



TEST(SubtractionTests, SubtractsAssociativelyCorrectly)
{
    std::unique_ptr<Constant> constant1_N10 = std::make_unique<Constant>(-10);
    std::unique_ptr<Constant> constant2_N10 = std::make_unique<Constant>(-10);
    std::unique_ptr<Constant> constant1_15 = std::make_unique<Constant>(15);
    std::unique_ptr<Constant> constant2_15 = std::make_unique<Constant>(15);
    Subtraction diffOfN10And15(std::move(constant1_N10), std::move(constant1_15));
    Subtraction diffOf15AndN10(std::move(constant2_15), std::move(constant2_N10));
    EXPECT_DOUBLE_EQ(diffOf15AndN10.calculate(), 25);
    EXPECT_DOUBLE_EQ(diffOfN10And15.calculate(), -25);
};