#ifndef HISTORY_H
#define HISTORY_H

////////////////////////////////////////////////////////////////////////////////
/**
* @file History.h
* @brief history function declarations.
*/
////////////////////////////////////////////////////////////////////////////////

#include "flatbuffers/flatbuffers.h"

namespace calculator {

/**
* @brief History interface which exposes to other components
*/

class History
{
    public:
        /**
         * @brief takes in a vector of history strings and serializes it into the history flatbuffer
         * @param [in] history a pointer to a created history class usd to track completed expressions
        */
        void serializeHistoryAndStoreOnDisk(const std::vector<std::string> &history);

        /**
         * @brief deserializes the history flatbuffer and prints all it's contents
        */
        void deserializeHistoryAndPrint(const std::string & fileName);

        /**
         * @brief creates a vector out of a string
         * @param [in] fullResult string of the full result taken from result object ex: "1+1 = 2"
        */
        void addToHistory(std::string fullResult);

        /**
         * @brief creates a vector out of a string
         * @returns allHistory_, a vector containing all the history strings
        */
        std::vector<std::string> getCurrentHistory();

        /**
         * @brief returns private variable historyFile_
         * @returns private variable historyFile_
        */
        std::string getHistoryFileName();

    private:
        std::vector<std::string> allHistory_ = std::vector<std::string>{};
        uint8_t *historyBufferptr_;
        const std::string historyFile_ = "historyData.bin";
};

} //namespace calculator

#endif //HISTORY_H