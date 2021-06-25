////////////////////////////////////////////////////////////////////////////
/**
 *  @file   Color.h
 *  @date   Thu, June 24 2021
 *  @brief  String Decorator Class for adding ANSI escape codes around a string
 *          Should work with *nix, may not work with Windows
 */
////////////////////////////////////////////////////////////////////////////

#pragma once

#include <string>

namespace calculator
{
    class Color
    {
        public:
            /**
             * @brief Make string red bold
             * @param string [in/out]
             * @return string ref made red bold
             */
            static std::string& error(std::string& string);

            /**
             * @brief Make string blue italic
             * @param string [in/out]
             * @return string ref made blue italic
             */
            static std::string& info(std::string& string);

            /**
             * @brief Make string green
             * @param string [in/out]
             * @return string ref made green
             */
            static std::string& message(std::string& string);

            /**
             * @brief Make string faint gray
             * @param string [in/out]
             * @return string ref made faint gray
             */
            static std::string& sub(std::string& string);


        private:
            static constexpr char blue[]    = "\033[94m";
            static constexpr char bold[]    = "\033[1m";
            static constexpr char faint[]   = "\033[2m";
            static constexpr char gray[]    = "\033[90m";
            static constexpr char green[]   = "\033[92m";
            static constexpr char italics[] = "\033[3m";
            static constexpr char red[]     = "\033[31m";
            static constexpr char reset[]   = "\033[0m";
    };
}

