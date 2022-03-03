////////////////////////////////////////////////////////////////////////////////
/**
 * @file ExpressionFactory.h
 * @date Fri February 25 2022
 * @brief header for a class with various static methods that can build an
 * expression tree
 */
////////////////////////////////////////////////////////////////////////////////

#ifndef EXPRESSION_FACTORY_H
#define EXPRESSION_FACTORY_H

#include <memory>
#include <set>
#include <utility>

#include <boost/optional.hpp>
#include <boost/utility/string_ref.hpp>

#include "IExpression.h"
#include "OperatorExpression.h"

namespace calculator { namespace expression
{

/**
 * @brief a class containing static methods which handle various ways of 
 * building a mathematical expression tree, usually by parsing strings 
 * representing that mathematical expression
 * @tparam T the type of numbers involved in this expression (int or double,
 * for example)
 */
template<typename T>
class ExpressionFactory
{
    public:
        /**
         * @brief attempts to parse mathematical expressions of the form "5 - 3"
         * aka simple, not compound, expressions which only contain literals
         * and a single operator
         * @param [in] singleOperationString the string to attempt to parse
         * @return std::unique_ptr<IExpression<T>> the parsed
         * expression or nullptr if the expression couldn't be successfully
         * parsed
         */
        static std::unique_ptr<IExpression<T>>
                parseFromSingleOperationString(
                const std::string &singleOperationString);

        /**
         * @brief attempts to parse arbitrary mathematical expressions which can contain literals, symbols, and binary
         * operators
         * @param [in] complexString the string from which to parse
         * @return std::unique_ptr<IExpression<T>> the parsed expression or nullptr if the expression couldn't be
         * successfully parsed
         */
        static std::unique_ptr<IExpression<T>>
                parseFromComplexString(const std::string &complexString);
    private:
        /**
         * @brief private constructor to ensure that objects can't be created
         */
        ExpressionFactory();

        /**
         * @brief Attempts to parse a literal value from the given input stream, updating the read head of the input
         * stream and returning the parsed value, if successful
         * @param [in] streamFromWhichToConsume the stream from which to consume the literal value
         * @return boost::optional<T> the literal value parsed, if any
         */
        static boost::optional<T> consumeValueFromStream(std::istream &streamFromWhichToConsume);

        /**
         * @brief Attempts to parse an operator from the given input stream, updating the read head of the input stream
         * and returning the parsed operator, if successful
         * @param [in] streamFromWhichToConsume the stream from which to consume the operator
         * @return boost::optional<T> the operator parsed, if any
         */
        static boost::optional<OperatorType> consumeOperatorFromStream(
                std::istream &streamFromWhichToConsume);

        /**
         * @brief Attempts to parse a symbol from the given input sream, updating the read head of the input stream and
         * returning the parsed operator, if successful
         * @param streamFromWhichToConsume the stream from which to consume the symbol
         * @return boost::optional<std::pair<bool, char>> whether the symbol is positive and the symbol itself
         */
        static boost::optional<std::pair<bool, char>> consumeSymbolFromStream(std::istream &streamFromWhichToConsume);

        /**
         * @brief attempts to parse arbitrary mathematical expressions which can contain literals, symbols, and binary
         * operators
         * @param [in] stringSlice the portion of a string from which to parse
         * @return std::unique_ptr<IExpression<T>> the parsed expression or nullptr if the expression couldn't be
         * successfully parsed
         */
        static std::unique_ptr<IExpression<T>>
                parseFromComplexStringInternal(boost::string_ref stringSlice);

        /**
         * @brief trims leading and trailing whitespace and matching sets of leading and trailing parentheses
         * @param [in,out] toTrim the string_ref from which to trim the whitespace
         */
        static bool trimUnneededCharacters(boost::string_ref &toTrim);

        /**
         * @brief trims white space from the front and back of a string_ref, modifying the string_ref in place
         * @param [in,out] toTrim the string_ref from which to trim the whitespace
         * @return true if changes occurred
         * @return false if changes did not occur
         */
        static bool trimWhiteSpace(boost::string_ref &toTrim);

        /**
         * @brief trims white space from the front of a string_ref, modifying the string_ref in place
         * @param [in,out] toTrim the string_ref from which to trim the whitespace
         * @return true if changes occurred
         * @return false if changes did not occur
         */
        static bool trimLeadingWhiteSpace(boost::string_ref &toTrim);

        /**
         * @brief trims white space from the back of a string_ref, modifying the string_ref in place
         * @param [in,out] toTrim the string_ref from which to trim the whitespace
         * @return true if changes occurred
         * @return false if changes did not occur
         */
        static bool trimTrailingWhiteSpace(boost::string_ref &toTrim);

        /**
         * @brief trims a pair of enclosing parentheses that are at the front and back of the string_view, if they exist
         * @param [in,out] toTrim the string_ref from which to trim the enclosing parentheses
         * @return true if changes occurred
         * @return false if changes did not occur
         */
        static bool trimEnclosingParentheses(boost::string_ref &toTrim);

        /**
         * @brief Searches the string for the next operator, respecting the order of operations and ignoring operators
         * within parentheses. As a caveat: "next" in the context of the parser is in reverse order compared to what one
         * might expect because the parser is always concerned with finding the next *root* node, that is, the *last* 
         * operator that needs to be evaluated in that sub-tree.
         * @param [in] stringSlice the string_ref to search
         * @return std::optional<std::pair<std::size_t, OperatorType>> the next operator and its position in the string,
         * if one was found
         */
        static boost::optional<std::pair<std::size_t, OperatorType>> findNextOperator(const boost::string_ref &stringSlice);

        /**
         * @brief attempts to parse the given string_ref into either a literal expression or a symbol expression
         * @param [in] stringSlice the string_ref to attempt to parse
         * @return std::unique_ptr<Expression<T>> nullptr if a simple expression could not be parsed from the given
         * string or if the given string contained more characters after parsing was completed
         */
        static std::unique_ptr<IExpression<T>> parseSimpleExpression(const boost::string_ref &stringSlice);

        /**
         * @brief because the minus sign could be an operator or part of a literal number, this function is used to
         * disambiguate between the two
         * @param [in] expressionString the string within which the minus sign resides
         * @param [in] minusPosition the positin within the string at which the minuus sign resides
         * @return true the minus sign at the given position represents an operator
         * @return false the minus sign at the given position is part of a number literal
         */
        static bool minusIsOperator(const boost::string_ref &expressionString, std::size_t minusPosition);
};

}}

#endif // #ifndef EXPRESSION_FACTORY_H
