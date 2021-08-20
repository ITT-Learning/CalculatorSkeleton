> IUnaryOperator, IBinaryOperator
>> Refactor using OpSymbol
> +,-,*,/,^,sqrt,inv,abs
4. OperatorFactory
5. Evaluator
6. Calculator
7. Errors
8. help

# AUtoReg
class OperatorFactory
    static bool RegisterOperator(OpSymbol os, IOperator::CreateMethod cm);
    std::map<std::string, IOperator::CreateMethod> operators_;
    bool OperatorFactory::RegisterOperator(OpSymbol os, IOperator::CreateMethod cm)
    {
        std::string id = os.Id();
        OPORDER order = os.Order();

        GetInstance()->operators_[id] = cm;
        GetInstance()->oporders_[order]->push_back(id);
        return true;
    }
class AbsoluteOperator : public IUnaryOperator
    const static OpSymbol OPSYMBOL;//("abs", OPORDER::THREE);
    static bool REGISTERED;
    static IOperator* CreateAbsoluteOperator();
        const OpSymbol AbsoluteOperator::OPSYMBOL("abs", OPORDER::THREE);

    bool AbsoluteOperator::REGISTERED = OperatorFactory::GetInstance()->RegisterOperator(AbsoluteOperator::OPSYMBOL, AbsoluteOperator::CreateAbsoluteOperator);//OperatorFactory::getInstance()->addOperator(new AbsoluteOperator);

    IOperator* AbsoluteOperator::CreateAbsoluteOperator()
    {
        return new AbsoluteOperator();
    }