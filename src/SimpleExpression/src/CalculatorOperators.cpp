////////////////////////////////////////////////////////////////////////////
/**
 *  @file   CalculatorOperators.cpp
 *  @date   Wed, June 16 2021
 *  @brief  Definitions for Calculator Operators
 */
////////////////////////////////////////////////////////////////////////////

#include "CalculatorOperators.h"

namespace calculator
{
    AddCalculator operator+(const ICalculator &calculator1, const ICalculator &calculator2)
    {
        return AddCalculator(calculator1.getResult(), calculator2.getResult());
    }

    SubtractCalculator operator-(const ICalculator &calculator1, const ICalculator &calculator2)
    {
        return SubtractCalculator(calculator1.getResult(), calculator2.getResult());
    }

    DivideCalculator operator/(const ICalculator &calculator1, const ICalculator &calculator2)
    {
        return DivideCalculator(calculator1.getResult(), calculator2.getResult());
    }

    MultiplyCalculator operator*(const ICalculator &calculator1, const ICalculator &calculator2)
    {
        return MultiplyCalculator(calculator1.getResult(), calculator2.getResult());
    }
}