#include "Multiplication.h"

#include <memory>
#include <thread>
#include <future>



Multiplication::Multiplication(std::unique_ptr<IMathOperation>&& lhs, std::unique_ptr<IMathOperation>&& rhs)
{
    lhs_ = std::move(lhs);
    rhs_ = std::move(rhs);

    leftDepth_  = lhs_->getDepth();
    rightDepth_ = rhs_->getDepth();
};



double Multiplication::calculate()
{
    double              lhsResult, rhsResult;
    std::future<double> future;

    if (leftDepth_ > THREADING_THRESHOLD && rightDepth_ > THREADING_THRESHOLD)
    {
        future = std::async(std::launch::async,
                                [this] ()->double
                                { return lhs_->calculate(); });
        rhsResult = rhs_->calculate();
        lhsResult = future.get();
    }
    else
    {
        lhsResult = lhs_->calculate();
        rhsResult = rhs_->calculate();
    }

    return lhsResult * rhsResult;
};



int Multiplication::getDepth()
{
    return std::max(leftDepth_, rightDepth_) + 1;
};