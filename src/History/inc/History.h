#ifndef HISTORY_H
#define HISTORY_H

////////////////////////////////////////////////////////////////////////////////
/**
* @file History.h
* @brief history function declarations.
*/
////////////////////////////////////////////////////////////////////////////////

#include <vector>
#include <string>

#include "flatbuffers/flatbuffers.h"
#include "history_generated.h"

namespace calculator {

/**
* @brief History interface which exposes to other components
*/

class History
{
    public:
        /**
         * @brief constructor for History
        */
        History();

        /**
         * @brief creates a vector out of a string
         * @param [in] fullResult string of the full result taken from result object ex: "1+1 = 2"
        */
        void addToHistory(std::string fullResult);

        /**
         * @brief prints all history
        */
        void printHistory();

    private:
        std::vector<std::string> allHistory_ = std::vector<std::string>{};
        const std::string historyFile_ =       "historyData.bin";
        bool hasHistoryFile_ =                 false;

        /**
         * @brief finds history file, and deserializes it into allHistory_
         * @returns true if there is a history file
        */
        bool findHistoryFileAndSetAllHistory();

        /**
         * @brief takes in a vector of history strings and serializes it into the history flatbuffer
         * @param [in] history a pointer to a created history class used to track completed expressions
        */
        void serializeHistoryAndStoreOnDisk(const std::vector<std::string> &history);

        /**
         * @brief deserializes the history and sets it to allhistory_
        */
        void deserializeHistory();

};

} //namespace calculator

#endif //HISTORY_H