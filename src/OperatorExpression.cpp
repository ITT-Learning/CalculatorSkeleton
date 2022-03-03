////////////////////////////////////////////////////////////////////////////////
/**
 * @file OperatorExpression.cpp
 * @date Fri February 25 2022
 * @brief implementation for a mathematical operator acting on two 
 * sub-expressions
 */
////////////////////////////////////////////////////////////////////////////////

#include "OperatorExpression.h"

#include <exception>
#include <cmath>

namespace calculator { namespace expression
{
// ---------------------------------------------------------------------------//
// //
// OperatorExpression<T> Public Methods //
// //
// ---------------------------------------------------------------------------//
template<typename T>
OperatorExpression<T>::OperatorExpression(
        std::unique_ptr<IExpression<T>> &&left,
        std::unique_ptr<IExpression<T>> &&right,
        OperatorType operatorType):
        left_{std::move(left)},
        right_{std::move(right)},
        operatorType_{operatorType}
{
    if(nullptr == left_ || nullptr == right_)
    {
        throw std::domain_error("sub-expressions must not be null");
    }
    switch(operatorType)
    {
        case OperatorType::ADDITION:
            safeOperatorFunction_ = [](T left, T right)
            {
                return boost::optional<T>{left + right};
            };
            operatorGlyph_ = '+';
            break;
        case OperatorType::SUBTRACTION:
            safeOperatorFunction_ = [](T left, T right)
            {
                return boost::optional<T>{left - right};
            };
            operatorGlyph_ = '-';
            break;
        case OperatorType::MULTIPLICATION:
            safeOperatorFunction_ = [](T left, T right)
            {
                return boost::optional<T>{left * right};
            };
            operatorGlyph_ = '*';
            break;
        case OperatorType::DIVISION:
            safeOperatorFunction_ = [](T left, T right)
            {
                boost::optional<T> result{boost::none};
                if(right != zero())
                {
                    result = left / right;
                }

                return result;
            };
            operatorGlyph_ = '/';
            break;
        case OperatorType::MODULO:
            safeOperatorFunction_ = &safeModulo;
            operatorGlyph_ = '%';
            break;
        default:
            throw std::domain_error("Unknown operator");
            // no break since an error was thrown
    }
}

template<typename T>
OperatorExpression<T>::~OperatorExpression() = default;

// ---------------------------------------------------------------------------//
// //
// IExpression<T> Public Methods //
// //
// ---------------------------------------------------------------------------//
template<typename T>
boost::optional<T> OperatorExpression<T>::calculateExpression() const
{
    boost::optional<T> result{boost::none};
    auto leftValue = left_->calculateExpression();
    if(leftValue)
    {
        // Do some short circuiting to avoid additional computation
        auto rightValue = right_->calculateExpression();
        if(rightValue)
        {
            result = safeOperatorFunction_(*leftValue, *rightValue);
        }
    }

    return result;
}

template<typename T>
std::unique_ptr<IExpression<T>> OperatorExpression<T>::
        bindValueToSymbol(char glyph, T value)
{
    std::unique_ptr<IExpression<T>> newLeft{nullptr};
    newLeft = left_->bindValueToSymbol(glyph, value);
    if(newLeft)
    {
        left_ = std::move(newLeft);
    }
    std::unique_ptr<IExpression<T>> newRight{nullptr};
    newRight = right_->bindValueToSymbol(glyph, value);
    if(newRight)
    {
        right_ = std::move(newRight);
    }

    return nullptr;
}

template<typename T>
std::string OperatorExpression<T>::toString() const
{
    return "(" + left_->toString() + " " + operatorGlyph_ + " " + 
            right_->toString() + ")";
}

// ---------------------------------------------------------------------------//
// //
// OperatorExpression<T> Private Methods //
// //
// ---------------------------------------------------------------------------//
template<>
int OperatorExpression<int>::zero()
{
    return 0;
}

template<>
boost::optional<int> OperatorExpression<int>::safeModulo(const int left, const int right)
{
    boost::optional<int> result{boost::none};
    if(right != zero())
    {
        result = left % right;
    }

    return result;
}

template<>
double OperatorExpression<double>::zero()
{
    return 0.0;
}

template<>
boost::optional<double> OperatorExpression<double>::safeModulo(const double left, const double right)
{
    boost::optional<double> result{boost::none};
    if(right != zero())
    {
        result = fmod(left, right);
    }
    
    return result;
}

template class OperatorExpression<int>;
template class OperatorExpression<double>;
}}
