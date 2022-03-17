////////////////////////////////////////////////////////////////////////////////
/**
 * @file ConsoleIo.h
 * @date Thu March 17 2022
 * @brief header for some static methods for handling calculator console I/O
 */
////////////////////////////////////////////////////////////////////////////////
#ifndef CONSOLEIO_H
#define CONSOLEIO_H

#include <memory>
#include <string>

#include "IExpression.h"
#include "ExpressionSerializer.h"

namespace calculator {

/**
 * @brief class with some static methods for handling calculator console I/O
 * @tparam T number type (int, double)
 */
template<typename T>
class ConsoleIo
{
public:
    /**
     * @brief top level prompt for handling what command the user wants to enter next
     * @param [in,out] savedExpressions a list of byte buffers of flatbuffer representations 
     * @return true the user quit
     * @return false the user did not quit
     */
    static bool handleInput(std::vector<typename expression::ExpressionSerializer<T>::ExpressionBuffer> &savedExpressions);
private:
    /**
     * @brief sub-prompt after the user has decided to enter in a new expression to parse that expression and store it
     * @param [in,out] savedExpressions a list of byte buffers of flatbuffer representations 
     */
    static void handleNewExpressionInput(std::vector<typename expression::ExpressionSerializer<T>::ExpressionBuffer> &savedExpressions);

    /**
     * @brief sub-prompt after the user has decided to evaluate an existing expression, entering values for variables
     * @param [in] savedExpressions a list of byte buffers of flatbuffer representations 
     */
    static void handleEvaluateExpressionInput(const std::vector<typename expression::ExpressionSerializer<T>::ExpressionBuffer> &savedExpressions);
    
    /**
     * @brief prompts the user to enter values for each variable in the given expression
     * @param [in] inputExpression the expression for which to prompt the user to enter variable values
     */
    static void bindSymbols(std::unique_ptr<expression::IExpression<T>> &inputExpression);
};

}

#endif