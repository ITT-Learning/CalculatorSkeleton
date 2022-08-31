#include<gtest/gtest.h>

#include<Calculator.h>

namespace
{

	// Test Calculator class Add function with positive numbers
	TEST(CalculatorTest, PositiveAdd)
	{
		EXPECT_EQ(5, Add(2, 3));
	}
	
	// Test Calculator class Add function with negative numbers
	TEST(CalculatorTest, NegativeAdd)
	{
		EXPECT_EQ(-1, Add(2, -3));
	}
	
	// Test Calculator class Add function with zero
	TEST(CalculatorTest, ZeroAdd)
	{
		EXPECT_EQ(0, Add(0, 0));
	}
	
	// Test Calculator class Subtract function with positive numbers
	TEST(CalculatorTest, PositiveSubtract)
	{
		EXPECT_EQ(1, Subtract(3, 2));
	}
	
	// Test Calculator class Subtract function with negative numbers
	TEST(CalculatorTest, NegativeSubtract)
	{
		EXPECT_EQ(-1, Subtract(2, 3));
	}

	// Test Calculator class Subtract function with zero
	TEST(CalculatorTest, ZeroSubtract)
	{
		EXPECT_EQ(4, Subtract(4, 0));
	}
	
	// Test Calculator class Multiply function with positive numbers
	TEST(CalculatorTest, PositiveMultiply)
	{
		EXPECT_EQ(6, Multiply(2, 3));
	}
	
	// Test Calculator class Multiply function with negative numbers
	TEST(CalculatorTest, NegativeMultiply)
	{
		EXPECT_EQ(-6, Multiply(2, -3));
	}
	
	// Test Calculator class Multiply function with zero
	TEST(CalculatorTest, ZeroMultiply)
	{
		EXPECT_EQ(0, Multiply(0, 0));
	}
	
	// Test Calculator class Divide function with positive numbers
	TEST(CalculatorTest, PositiveDivide)
	{
		EXPECT_EQ(2, Divide(4, 2));
	}
	
	// Test Calculator class Divide function with negative numbers
	TEST(CalculatorTest, NegativeDivide)
	{
		EXPECT_EQ(-2, Divide(4, -2));
	}
	
	// Test Calculator class Divide function with zero as numerator
	TEST(CalculatorTest, DivideZero)
	{
		EXPECT_EQ(0, Divide(0, 2));
	}
	
	// Test Calculator class Divide function with zero as divisor checking for error thrown
	TEST(CalculatorTest, ZeroDivide)
	{
		EXPECT_THROW(Divide(4, 0), std::invalid_argument);
	}
}