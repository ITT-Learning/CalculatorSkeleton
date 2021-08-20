/**
 * @file OperatorFactory.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef OPERATORFACTORY_H
#define OPERATORFACTORY_H

#include <map>
#include <vector>

#include "IOperator.h"

namespace Calculator
{
    class OperatorFactory
    {
        public:
            static OperatorFactory* GetInstance();
            ~OperatorFactory();
            IOperator* GetOperator(std::string opId);
            std::vector<std::string>* GetOperatorListByOporder(OPORDER oporder);

            static bool RegisterOperator(IOperator* op);

        private:
            OperatorFactory();
            static OperatorFactory *instance_;
            std::map<std::string, IOperator*> operators_;
            std::map<OPORDER, std::vector<std::string>*> oporders_;
    };
}

#endif //OPERATORFACTORY_H