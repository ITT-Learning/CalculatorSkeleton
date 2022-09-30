#include "Addition.h"

#include <memory>

Addition::Addition(std::unique_ptr<IMathOperation>&& lhs, std::unique_ptr<IMathOperation>&& rhs)
{
    lhs_ = std::move(lhs);
    rhs_ = std::move(rhs);
};



double Addition::calculate() const
{
    return lhs_->calculate() + rhs_->calculate();
};