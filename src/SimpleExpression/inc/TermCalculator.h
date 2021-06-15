////////////////////////////////////////////////////////////////////////////
/**
 *  @file   TermCalculator.h
 *  @date   Tue, June 15 2021
 *  @brief  Calculator that represents a single term
 */
////////////////////////////////////////////////////////////////////////////

#ifndef CALCULATOR_TERMCALCULATOR_H
#define CALCULATOR_TERMCALCULATOR_H

#include "ICalculator.h"

namespace calculator {
    class TermCalculator : public ICalculator
    {
        public:
            TermCalculator() = delete;

            explicit TermCalculator(int term);

            std::string getExpression() const final;

            int getResult() const final;

            std::string toString() const final;

        private:
            int term_;
    };
}


#endif //CALCULATOR_TERMCALCULATOR_H
