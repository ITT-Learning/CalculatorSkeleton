#include "Addition.h"

#include <memory>
#include <future>
#include <thread>



Addition::Addition(std::unique_ptr<IMathOperation>&& lhs, std::unique_ptr<IMathOperation>&& rhs)
{
    using namespace std::literals::chrono_literals;
    lhs_ = std::move(lhs);
    rhs_ = std::move(rhs);

    leftDepth_  = lhs_->getDepth();
    rightDepth_ = rhs_->getDepth();
};



double Addition::calculate()
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

    return lhsResult + rhsResult;
};



int Addition::getDepth()
{
    return std::max(leftDepth_, rightDepth_) + 1;
};