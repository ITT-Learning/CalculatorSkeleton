////////////////////////////////////////////////////////////////////////////
/**
 *  @file   CalculatorOperators.h
 *  @date   Wed, June 16 2021
 *  @brief  Overloaded Operators for Calculators
 */
////////////////////////////////////////////////////////////////////////////

#ifndef CALCULATOR_CALCULATOROPERATORS_H
#define CALCULATOR_CALCULATOROPERATORS_H


#include "ICalculator.h"
#include "AddCalculator.h"
#include "DivideCalculator.h"
#include "MultiplyCalculator.h"
#include "SubtractCalculator.h"

namespace calculator
{
    /**
     * @brief Overload+ to add two calculators together order does not matter
     * @param calculator1 [in] left term calculator
     * @param calculator2 [in] right term calculator
     * @return AddCalculator constructed with calculator1.getResult() + calculator2.getResult()
     */
    AddCalculator operator+(const ICalculator &calculator1, const ICalculator &calculator2);

    /**
     * @brief Overload- to subtract two calculators; order matters
     * @param calculator1 [in] left term calculator
     * @param calculator2 [in] right term calculator
     * @return SubtractCalculator constructed with calculator1.getResult() - calculator2.getResult()
     */
    SubtractCalculator operator-(const ICalculator &calculator1, const ICalculator &calculator2);

    /**
     * @brief Overload* to multiply two calculators together order does not matter
     * @param calculator1 [in] left term calculator
     * @param calculator2 [in] right term calculator
     * @return MultiplyCalculator constructed with calculator1.getResult() * calculator2.getResult()
     */
    MultiplyCalculator operator*(const ICalculator &calculator1, const ICalculator &calculator2);

    /**
     * @brief Overload/ to divide two calculators; order matters
     * @param calculator1 [in] left term calculator
     * @param calculator2 [in] right term calculator
     * @return DivideCalculator constructed with calculator1.getResult() / calculator2.getResult()
     */
    DivideCalculator operator/(const ICalculator &calculator1, const ICalculator &calculator2);
}

#endif //CALCULATOR_CALCULATOROPERATORS_H
