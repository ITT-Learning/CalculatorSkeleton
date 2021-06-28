////////////////////////////////////////////////////////////////////////////
/**
 *  @file   History.cpp
 *  @date   Tue, June 22 2021
 *  @brief  Singleton containing calculator history
 */
////////////////////////////////////////////////////////////////////////////

#include "History.h"

#include "CompoundExpressionCalculator.h"
#include "CustomCalculator.h"
#include "SimpleExpressionCalculator.h"
#include "TermCalculator.h"

namespace calculator
{
    std::shared_ptr<History> History::instance_ = nullptr;

    void History::appendCalculator(const ICalculator& calculator)
    {
        flatbuffers::FlatBufferBuilder builder;

        schema::CalculatorType type;

        //this feels dirty
        if (dynamic_cast<const TermCalculator*>(&calculator))
        {
            type = schema::CalculatorType_Term;
        }
        else if (dynamic_cast<const SimpleExpressionCalculator*>(&calculator))
        {
            type = schema::CalculatorType_Simple;
        }
        else if (dynamic_cast<const CompoundExpressionCalculator*>(&calculator))
        {
            type = schema::CalculatorType_Compound;
        }
        else
        {
            type = schema::CalculatorType_MIN;
        }

        auto equation = builder.CreateString(calculator.toString());
        auto expression = builder.CreateString(calculator.getExpression());
        schema::CalculatorBuilder calculatorBuilder(builder);
        calculatorBuilder.add_result(calculator.getResult());
        calculatorBuilder.add_expression(expression);
        calculatorBuilder.add_full_equation(equation);
        calculatorBuilder.add_type(type);
        auto calculatorOffset = calculatorBuilder.Finish();
        builder.Finish(calculatorOffset);

        calculators_.push_back(schema::GetCalculator(builder.GetBufferPointer())->UnPack());
    }

    void History::clear()
    {
        calculators_.clear();
    }

    schema::HistoryT *History::getBuiltHistory()
    {
        flatbuffers::FlatBufferBuilder builder(1024);
        schema::HistoryT *history = nullptr;

        std::vector<flatbuffers::Offset<schema::Calculator>> offsetCalculators;

        for(auto calculator : calculators_)
        {
            offsetCalculators.push_back(schema::Calculator::Pack(builder,calculator));
        }
        auto historyCalculators = builder.CreateVector(offsetCalculators);
        auto builtHistory = schema::CreateHistory(builder, historyCalculators);

        builder.Finish(builtHistory);

        history = schema::GetHistory(builder.GetBufferPointer())->UnPack();

        return history;
    }

    const schema::CalculatorT *History::getCalculator(int index)
    {
        const schema::CalculatorT *calculator = nullptr;
        int size = calculators_.size();

        if (index >= 0 && index < size)
        {
            calculator = calculators_[index];
        }

        return calculator;
    }

    std::shared_ptr<History> History::getInstance()
    {
        if (!instance_)
        {
            instance_ = std::shared_ptr<History>(new History());
        }
        return instance_;
    }

    int History::getSize()
    {
        return calculators_.size();
    }

}