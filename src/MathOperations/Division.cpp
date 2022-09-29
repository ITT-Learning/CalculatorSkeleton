#include "Division.h"

#include <cmath>
#include <memory>
#include <thread>
#include <future>



Division::Division(std::unique_ptr<IMathOperation>&& lhs, std::unique_ptr<IMathOperation>&& rhs)
{
    lhs_ = std::move(lhs);
    rhs_ = std::move(rhs);

    leftDepth_  = lhs_->getDepth();
    rightDepth_ = rhs_->getDepth();
};



double Division::calculate()
{
    double              lhsResult, rhsResult;
    std::future<double> future;

    if (leftDepth_ > THREADING_THRESHOLD && rightDepth_ > THREADING_THRESHOLD)
    {
        // if(leftDepth_ <= rightDepth_)
        // {
            future = std::async(std::launch::async,
                                   [this] ()->double
                                   { return lhs_->calculate(); });
            rhsResult = rhs_->calculate();
            lhsResult = future.get();
        // }
        // else
        // {
            // future = std::async(std::launch::async,
                                //    [this] ()->double
                                //    { return rhs_->calculate(); });
            // lhsResult = lhs_->calculate();
// 
        // }
    }
    else
    {
        lhsResult = lhs_->calculate();
        rhsResult = rhs_->calculate();
    }

    if (rhsResult != 0)
    {
        return lhsResult / rhsResult;
    }
    else
    {
        return nan("");
    }
};


int Division::getDepth()
{
    return std::max(leftDepth_, rightDepth_) + 1;
};