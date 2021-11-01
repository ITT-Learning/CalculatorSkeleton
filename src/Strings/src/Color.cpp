////////////////////////////////////////////////////////////////////////////
/**
 *  @file   Color.cpp
 *  @date   Thu, June 24 2021
 *  @brief  String Decorator Class for adding ANSI escape codes around a string
 */
////////////////////////////////////////////////////////////////////////////

#include "Color.h"

namespace calculator
{
    constexpr char Color::blue[];
    constexpr char Color::bold[];
    constexpr char Color::faint[];
    constexpr char Color::gray[];
    constexpr char Color::green[];
    constexpr char Color::italics[];
    constexpr char Color::red[];
    constexpr char Color::reset[];

    std::string &Color::error(std::string &string)
    {
        string = std::string(red) + bold + string + reset;
        return string;
    }

    std::string &Color::info(std::string &string)
    {
        string = std::string(blue) + italics + string + reset;
        return string;
    }

    std::string &Color::message(std::string &string)
    {
        string = std::string(green) + string + reset;
        return string;
    }

    std::string &Color::sub(std::string &string)
    {
        string = std::string(gray) + faint + string + reset;
        return string;
    }
}