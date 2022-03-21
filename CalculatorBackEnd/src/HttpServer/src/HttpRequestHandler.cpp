#include <iostream>
#include <filesystem>

#include <boost/optional.hpp>
#include <boost/utility/string_ref.hpp>
#include <nlohmann/json.hpp>
#include <pistache/router.h>

#include "ExpressionFactory.h"
#include "ExpressionSerializer.h"
#include "HttpRequestHandler.h"

namespace calculator { namespace httpserver
{
// ---------------------------------------------------------------------------//
// //
// CalculatorEndPoint<T> Public Methods //
// //
// ---------------------------------------------------------------------------//
template<typename T>
CalculatorEndPoint<T>::CalculatorEndPoint(Pistache::Address address, size_t threads) :
        internalEndPoint_(std::make_shared<Pistache::Http::Endpoint>(address))
{
    initializeRoutes();
    initializeEndPoint(threads);
}

template<typename T>
void CalculatorEndPoint<T>::start()
{
    internalEndPoint_->serve();
}

// ---------------------------------------------------------------------------//
// //
// CalculatorEndPoint<T> Private Methods //
// //
// ---------------------------------------------------------------------------//
template<typename T>
void CalculatorEndPoint<T>::initializeRoutes()
{
    // API routes
    Pistache::Rest::Routes::Get(router_, RoutingConstants::ROUTE_LIST, Pistache::Rest::Routes::bind(&CalculatorEndPoint<T>::handleApiList, this));
    Pistache::Rest::Routes::Post(router_, RoutingConstants::ROUTE_STORE, Pistache::Rest::Routes::bind(&CalculatorEndPoint<T>::handleApiStore, this));
    Pistache::Rest::Routes::Post(router_, RoutingConstants::ROUTE_CALCULATE, Pistache::Rest::Routes::bind(&CalculatorEndPoint<T>::handleApiCalculate, this));

    // file resource routes
    router_.addCustomHandler(&handleFileResource);
}

template<typename T>
void CalculatorEndPoint<T>::initializeEndPoint(size_t threads)
{
    internalEndPoint_->init(Pistache::Http::Endpoint::options().threads(static_cast<int>(threads)));
    internalEndPoint_->setHandler(router_.handler());
}

template<typename T>
Pistache::Rest::Route::Result CalculatorEndPoint<T>::handleApiStore(const Pistache::Rest::Request& request, Pistache::Http::ResponseWriter response)
{
    Pistache::Rest::Route::Result result = Pistache::Rest::Route::Result::Failure;
    Pistache::Http::Code responseCode = Pistache::Http::Code::Bad_Request;
    nlohmann::json responseBodyJson =
    {
        {JsonConstants::RESPONSETYPE_KEY, JsonConstants::ResponseTypes::STORE},
        {JsonConstants::RESPONSEDATA_KEY,
        {
            {JsonConstants::DataKeys::EXPRESSION, nullptr}
        }}
    };
    auto requestBodyJson = nlohmann::json::parse(request.body(), nullptr, false);
    if(!requestBodyJson.is_discarded() && requestBodyJson[JsonConstants::REQUESTTYPE_KEY] == JsonConstants::RequestTypes::STORE)
    {
        auto expression = expression::ExpressionFactory<T>::parseFromComplexString(requestBodyJson[JsonConstants::REQUESTDATA_KEY][JsonConstants::DataKeys::EXPRESSION][JsonConstants::DataKeys::ExpressionKeys::STRING]);
        if(nullptr != expression)
        {
            std::size_t id;

            auto value = expression->calculateExpression();
            nlohmann::json valueJson{nullptr};
            if(boost::none != value)
            {
                valueJson = *value;
            }

            std::set<char> variables;
            expression->collectUnboundSymbols(variables);
            std::vector<char> variablesList{variables.begin(), variables.end()};
            std::sort(variablesList.begin(), variablesList.end());

            // Why the map here instead of an array? Standardization - It may be convenient if expressions in JSON
            // always look the same, so we use a map to allow the client to set variable values and request a
            // calculation.
            std::map<char, nlohmann::json> variablesMap;
            for(const auto &variable : variablesList)
            {
                variablesMap[variable] = nlohmann::json{nullptr};
            }

            auto expressionBuffer = expression::ExpressionSerializer<T>::serialize(*expression);
            {
                std::lock_guard<std::mutex> guard{savedExpressionsLock_};
                savedExpressions_.push_back(std::move(expressionBuffer));
                id = savedExpressions_.size() - 1;
            }
            responseBodyJson[JsonConstants::RESPONSEDATA_KEY][JsonConstants::DataKeys::EXPRESSION] = 
            {
                {JsonConstants::DataKeys::ExpressionKeys::ID, id},
                {JsonConstants::DataKeys::ExpressionKeys::STRING, expression::IExpression<T>::toString(*expression)},
                {JsonConstants::DataKeys::ExpressionKeys::VALUE, valueJson},
                {JsonConstants::DataKeys::ExpressionKeys::VARIABLES, variablesMap}
            };
            result = Pistache::Rest::Route::Result::Ok;
            responseCode = Pistache::Http::Code::Created;
        }
    }
    response.send(responseCode, responseBodyJson.dump());
    return result;
}

template<typename T>
Pistache::Rest::Route::Result CalculatorEndPoint<T>::handleApiList(const Pistache::Rest::Request& request, Pistache::Http::ResponseWriter response)
{
    Pistache::Rest::Route::Result result = Pistache::Rest::Route::Result::Failure;
    auto requestBodyJson = nlohmann::json::parse(request.body(), nullptr, false);
    if(!requestBodyJson.is_discarded() && requestBodyJson[JsonConstants::REQUESTTYPE_KEY] == JsonConstants::RequestTypes::LIST)
    {

    }
    std::lock_guard<std::mutex> guard{savedExpressionsLock_};
    nlohmann::json responseBodyJson;
    return result;
}

template<typename T>
Pistache::Rest::Route::Result CalculatorEndPoint<T>::handleApiCalculate(const Pistache::Rest::Request& request, Pistache::Http::ResponseWriter response)
{

}

template<typename T>
Pistache::Rest::Route::Result CalculatorEndPoint<T>::handleFileResource(const Pistache::Rest::Request& request, Pistache::Http::ResponseWriter response)
{
    Pistache::Rest::Route::Result result = Pistache::Rest::Route::Result::Ok;
    if(request.method() != Pistache::Http::Method::Get)
    {
        result = Pistache::Rest::Route::Result::Failure;
    }
    else
    {
        boost::string_ref resourceStringRef = request.resource();
        // We always iterate over the files in the file root directory to ensure that, even if a file is added or
        // removed after the server is started, the server will know of those changes. A caching solution would have
        // better performance, but that's some more work that I don't have the time for right now.

        // the filesystem module is C++17, but I had to bump up to C++17 for Pistache anyway.
        std::filesystem::path fileRootDirectoryPath{FILE_ROOT_DIRECTORY};
        std::filesystem::recursive_directory_iterator fileRootDirectoryIterator{fileRootDirectoryPath};
        bool fileFound = false;
        for(const auto &currentFile : fileRootDirectoryIterator)
        {
            const auto &filePath = currentFile.path();
            boost::string_ref filePathStringRef{filePath.string()};
            if(filePathStringRef.ends_with(resourceStringRef))
            {
                Pistache::Http::serveFile(response, filePathStringRef.to_string());
                fileFound = true;
                break;
            }
        }
        if(!fileFound)
        {
            result = Pistache::Rest::Route::Result::Failure;
        }
    }
    return result;
}

template<typename T>
nlohmann::json CalculatorEndPoint<T>::expressionToJson(std::size_t id, boost::optional<const CalculatorEndPoint<T>::VariableAssignments &> variableAssignments)
{
    nlohmann::json result{nullptr};
    std::unique_ptr<expression::IExpression<T>> expression{nullptr};
    {
        std::lock_guard<std::mutex> guard{savedExpressionsLock_};
        if(id > savedExpressions_.size())
        {
            expression = expression::ExpressionSerializer<T>::deserialize(savedExpressions_[id]);
        }
    }
    if(nullptr != expression)
    {
        if(boost::none != variableAssignments)
        {
            for(const auto &variableAssignment: VariableAssignments)
            {
                auto newExpression = expression->bindValueToSymbol(variableAssignment, VariableAssignments[variableAssignments]);
                if(nullptr != newExpression)
                {
                    expression = newExpression;
                }
            }
        }
        auto expressionValue = expression->calculateExpression();
        nlohmann::json jsonValue{nullptr};
        if(boost::none != expressionValue)
        {
            jsonValue = *expressionValue;
        }
        nlohmann::json jsonVariableAssignments{nullptr};
        if(boost::none != variableAssignments)
        {
            jsonVariableAssignments = *variableAssignments;
        }
        nlohmann::json result =
        {
            {JsonConstants::DataKeys::ExpressionKeys::ID, id},
            {JsonConstants::DataKeys::ExpressionKeys::STRING, expression::IExpression<T>::toString(*expression)},
            {JsonConstants::DataKeys::ExpressionKeys::VALUE, jsonValue},
            {JsonConstants::DataKeys::ExpressionKeys::VARIABLES, jsonVariableAssignments}
        };
    }
}

template class CalculatorEndPoint<int>;
template class CalculatorEndPoint<double>;

}}