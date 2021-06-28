////////////////////////////////////////////////////////////////////////////
/**
 *  @file   History.h
 *  @date   Tue, June 22 2021
 *  @brief  Singleton containing the history
 */
////////////////////////////////////////////////////////////////////////////

#ifndef CALCULATOR_HISTORY_H
#define CALCULATOR_HISTORY_H

#include <memory>
#include <vector>

#include "calculator_generated.h"
#include "flatbuffers/flatbuffers.h"
#include "history_generated.h"

#include "ICalculator.h"
#include "TermCalculator.h"

namespace calculator {
    class History
    {
        public:
            /**
             * @brief delete copy constructors
             */
            History(History const&)        = delete;
            void operator=(History const&) = delete;

            ~History() = default;

            /**
             * @brief creates a flat buffer object from ICalculator and appends it to calculators_
             * @param calculator [in]
             */
            void appendCalculator(const ICalculator& calculator);

            /**
             * @brief exposes calculators_.clear()
             */
            void clear();

            /**
             * @brief Get flatbuffer object of the history containing all calculators
             * @return faltbuffer history object
             */
            schema::HistoryT *getBuiltHistory();

            /**
             * @brief Get the flatbuffer calculator object from calculators_
             * @param index [in] index of calculator from container
             * @return calculatorT if index is valid, otherwise returns nullptr
             */
            const schema::CalculatorT *getCalculator(int index);

            /**
             * @brief returns the Singleton instance, will construct History if needed
             * @return History singleton instance
             */
            static std::shared_ptr<History> getInstance();

            /**
             * @brief exposes calculators_.size()
             * @return int - size of calculators_
             */
            int getSize();

        private:
            std::vector<const schema::CalculatorT*> calculators_;
            static std::shared_ptr<History>         instance_;

            /**
             * @brief Hide default constructor
             */
            History() = default;
    };
}

#endif //CALCULATOR_HISTORY_H
