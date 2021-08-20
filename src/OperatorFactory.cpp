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

#include "AbsoluteOperator.h"
#include "AdditionOperator.h"
#include "CalculatorResources.h"
#include "DivisionOperator.h"
#include "ExponentOperator.h"
#include "InverseOperator.h"
#include "MultiplicationOperator.h"
#include "OperatorFactory.h"
#include "SquareRootOperator.h"
#include "SubtractionOperator.h"

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
        for (OPORDER order : OPORDERS)
        {
            oporders_[order] = new std::vector<std::string>;
        }

        RegisterOperator(new AbsoluteOperator);
        RegisterOperator(new AdditionOperator);
        RegisterOperator(new DivisionOperator);
        RegisterOperator(new ExponentOperator);
        RegisterOperator(new InverseOperator);
        RegisterOperator(new MultiplicationOperator);
        RegisterOperator(new SquareRootOperator);
        RegisterOperator(new SubtractionOperator);
    }

    OperatorFactory::~OperatorFactory()
    {
        for (OPORDER order : OPORDERS)
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

    void OperatorFactory::RegisterOperator(IOperator *op)
    {
        std::string id = op->GetOpSymbol().Id();
        OPORDER order = op->GetOpSymbol().Order();

        operators_[id] = op;
        oporders_[order]->push_back(id);
    }
}