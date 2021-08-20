/**
 * @file OperatorFactor.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "CalculatorResources.h"
#include "OperatorFactory.h"

namespace Calculator
{
    OperatorFactory* OperatorFactory::instance_ = nullptr;

    OperatorFactory* OperatorFactory::GetInstance()
    {
        if (instance_ == nullptr)
        {
            instance_ = new OperatorFactory();
        }

        return instance_;
    }

    OperatorFactory::OperatorFactory()
    {
        for (OPORDER order : GetOpOrders())
        {
            oporders_[order] = new std::vector<std::string>;
        }
    }

    OperatorFactory::~OperatorFactory()
    {
        for (OPORDER order : GetOpOrders())
        {
            delete oporders_[order];
        }

        for (auto op : operators_) {
            delete op.second;
        }
    }

    IOperator* OperatorFactory::GetOperator(std::string opId)
    {
        return operators_[opId];
    }

    std::vector<std::string>* OperatorFactory::GetOperatorListByOporder(OPORDER opOrder)
    {
        return oporders_[opOrder];
    }

    bool OperatorFactory::RegisterOperator(IOperator *op)
    {
        std::string id = op->GetOpSymbol().Id();
        OPORDER order = op->GetOpSymbol().Order();

        GetInstance()->operators_[id] = op;
        GetInstance()->oporders_[order]->push_back(id);

        return true;
    }

    std::vector<OPORDER> OperatorFactory::GetOpOrders()
    {
        return std::vector<OPORDER> {
            OPORDER::ZERO,
            OPORDER::ONE,
            OPORDER::TWO,
            OPORDER::THREE,
            OPORDER::FOUR,
            OPORDER::FIVE,
            OPORDER::SIX
        };
    }
}