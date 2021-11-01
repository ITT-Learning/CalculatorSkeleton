#ifndef HISTORY_H
#define HISTORY_H

////////////////////////////////////////////////////////////////////////////
/**
 *  @file   History.h
 * @author Jeff Trent
 *  @date   Tue, June 22 2021
 *  @brief  Singleton containing the history
 */
////////////////////////////////////////////////////////////////////////////

#include <memory>
#include <vector>

#include "calculator_generated.h"
#include "Color.h"
#include "flatbuffers/flatbuffers.h"
#include "history_generated.h"
#include "ICalculator.h"

namespace calculator {

/**
* @brief History interface which exposes to other components
*
*/

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
         * @param answer [in] float containing the final answer
         * @param originalEquation string containing the originalEquation
         */
        void appendCalculator(float answer, std::string originalEquation);

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
        const schema::CalculatorDataT *getCalculatorData(int index);

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

        /**
         * @brief Places storedHistory from appendCalculator into outputFile
         */
        void storedHistory();

    private:
        std::vector<const schema::CalculatorDataT*> calculators_;

        static std::shared_ptr<History>         instance_;

        /**
         * @brief Hide default constructor
         */
        History() = default;
};

} // namespace caluculator

#endif //HISTORY_H
