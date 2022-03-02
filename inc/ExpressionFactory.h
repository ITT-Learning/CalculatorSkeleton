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

#include <boost/optional.hpp>

#include "ExpressionInterface.h"
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
         * @param [in] string the string to attempt to parse
         * @return std::unique_ptr<ExpressionInterface<T> *> the parsed
         * expression or nullptr if the expression couldn't be successfully
         * parsed
         */
        static std::unique_ptr<ExpressionInterface<T>>
                parseFromSingleOperationString(
                const std::string &string);
    private:
        static boost::optional<T> consumeValueFromStream(std::istream &stream);
        static boost::optional<OperatorType> consumeOperatorFromStream(
                std::istream &stream);
};

}}

#endif // #ifndef EXPRESSION_FACTORY_H
