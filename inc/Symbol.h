////////////////////////////////////////////////////////////////////////////////
/**
 * @file Symbol.h
 * @date Wed February 23 2022
 * @brief Header for a class which can be used to represent a symbol in a 
 * mathematical expression and, optionally, its associated numerical value.
 */
////////////////////////////////////////////////////////////////////////////////

#ifndef SYMBOL_H
#define SYMBOL_H

#include <iostream>

namespace calculator {

/**
 * @brief Represents a symbol in a mathematical expression. Symbols have a 
 * single associated glyph from a-z and can optionally have a value (e.g. int or
 * double) bound to them.
 */
template<typename T>
class Symbol
{
    public:
        /**
         * @brief Default value returned by getValue() when no value has been
         * bound to the symbol
         * @return T The default value
         */
        static T defaultValue();

        /**
         * @brief Construct a new Symbol object
         * @param symbol the character glyph associated with the object
         */
        Symbol(char symbol);

        /**
         * @brief Get the character glyph associated with the object
         * @return char the character glyph associated with the object
         */
        char getSymbol();

        /**
         * @brief whether the symbol has a value (e.g. int or double) bound to 
         * it
         * @return true the symbol had a value
         * @return false the symbol did not have a value
         */
        bool hasValue() const;

        /**
         * @brief Set the value (e.g. int or double) associated with the symbol
         * @param valueToBind The value (e.g. int or double) to associate with 
         *      this symbol
         */
        void setValue(T valueToBind);

        /**
         * @brief Get the value (e.g. int or double) associated with the symbol
         * @return T The value (e.g. int or double) associated with this symbol
         */
        T getValue() const;

        /**
         * @brief Binds a value (e.g. int or double) to the symbol using values
         * from an input stream, providing feedback to an output stream
         * @param istream The stream from which to pull the value
         * @param ostream The stream to which to provide feedback
         */
        void bindFromStreams(std::istream &istream, std::ostream &ostream);
    private:
        const char symbol_;
        bool isBound_;
        T boundValue_;
};

}

#endif // #ifndef SYMBOL_H