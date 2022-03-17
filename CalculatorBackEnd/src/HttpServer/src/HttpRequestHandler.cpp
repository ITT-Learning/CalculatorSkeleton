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
    Pistache::Rest::Routes::Get(router_, ROUTE_LIST, Pistache::Rest::Routes::bind(&CalculatorEndPoint<T>::handleApiList, this));
    Pistache::Rest::Routes::Post(router_, ROUTE_STORE, Pistache::Rest::Routes::bind(&CalculatorEndPoint<T>::handleApiStore, this));
    Pistache::Rest::Routes::Post(router_, ROUTE_CALCULATE, Pistache::Rest::Routes::bind(&CalculatorEndPoint<T>::handleApiCalculate, this));

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
    Pistache::Rest::Route::Result result = Pistache::Rest::Route::Result::Ok;
    auto requestBodyJson = nlohmann::json::parse(request.body(), nullptr, false);
    // TODO figure out how the json library handles accessing elements that do not exist
    if(requestBodyJson.is_discarded() || requestBodyJson[JsonConstants::REQUESTTYPE_KEY] != JsonConstants::RequestTypes::STORE)
    {
        result = Pistache::Rest::Route::Result::Failure;
    }
    else
    {
        auto expression = expression::ExpressionFactory<T>::parseFromComplexString(requestBodyJson[JsonConstants::REQUESTDATA_KEY][]);
        if(nullptr != expression)
        {
            auto expressionBuffer = expression::ExpressionSerializer<T>::serialize(*expression);
            {
                std::lock_guard<std::mutex> guard{savedExpressionsLock_};
                savedExpressions_.push_back(std::move(expressionBuffer));
            }
        }
    }
    return result;
}

template<typename T>
Pistache::Rest::Route::Result CalculatorEndPoint<T>::handleApiList(const Pistache::Rest::Request& request, Pistache::Http::ResponseWriter response)
{
    std::lock_guard<std::mutex> guard{savedExpressionsLock_};

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

template class CalculatorEndPoint<int>;
template class CalculatorEndPoint<double>;

}}