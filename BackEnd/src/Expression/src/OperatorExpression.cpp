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
#include <thread>
#include <flatbuffers/flatbuffers.h>

#include "Expression_generated.h"

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
            break;
        case OperatorType::SUBTRACTION:
            safeOperatorFunction_ = [](T left, T right)
            {
                return boost::optional<T>{left - right};
            };
            break;
        case OperatorType::MULTIPLICATION:
            safeOperatorFunction_ = [](T left, T right)
            {
                return boost::optional<T>{left * right};
            };
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
            break;
        case OperatorType::MODULO:
            safeOperatorFunction_ = &safeModulo;
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
    if(boost::none == cachedValue_)
    {
        // since expressions are immutable, just checking whether a cached value
        // exists is a good enough check - the cached value will never be stale

        // the following threading is safe despite any synchronization
        // primitives because the main thread will block here on the root node
        // until the sub-trees compute their values, and, in addition, the only
        // method that accesses expression trees for writing after their
        // creation is bindValueToSymbol(), which is not called in
        // calculateExpression() or any of the functions that it calls.
        boost::optional<T> leftValue{boost::none};
        boost::optional<T> rightValue{boost::none};
        std::thread leftThread{[&](){
            leftValue = left_->calculateExpression();
        }};
        std::thread rightThread{[&](){
            rightValue = right_->calculateExpression();
        }};
        leftThread.join();
        rightThread.join();
        if(boost::none != leftValue && boost::none != rightValue)
        {
            cachedValue_ = safeOperatorFunction_(*leftValue, *rightValue);
        }
    }

    return cachedValue_;
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
void OperatorExpression<T>::collectUnboundSymbols(std::set<char> &unboundSymbols) const
{
    left_->collectUnboundSymbols(unboundSymbols);
    right_->collectUnboundSymbols(unboundSymbols);
}

template<typename T>
std::string OperatorExpression<T>::toString() const
{
    return "(" + left_->toString() + " " + static_cast<char>(operatorType_) + " " + 
            right_->toString() + ")";
}

template<typename T>
flatbuffer::ExpressionUnion OperatorExpression<T>::toFlatBufferObject() const
{
    flatbuffer::ExpressionUnion result;
    flatbuffer::OperatorExpressionT resultData;
    resultData.operator_ = static_cast<flatbuffer::Operator>(operatorType_);
    resultData.left = left_->toFlatBufferObject();
    resultData.right = right_->toFlatBufferObject();
    result.Set<flatbuffer::OperatorExpressionT>(std::move(resultData));
    return result;
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
