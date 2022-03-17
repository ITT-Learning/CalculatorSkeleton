////////////////////////////////////////////////////////////////////////////////
/**
 * @file HttpRequestHandler.h
 * @date Wed March 16 2022
 * @brief header for a class that handles the HTTP requests for the server
 */
////////////////////////////////////////////////////////////////////////////////
#ifndef HTTPREQUESTHANDLER_H
#define HTTPREQUESTHANDLER_H

#include <mutex>

#include <pistache/endpoint.h>
#include <pistache/http.h>

#include "ExpressionSerializer.h"

namespace calculator { namespace httpserver
{

template<typename T>
class CalculatorEndPoint
{
    public:
        CalculatorEndPoint(Pistache::Address address, size_t threads = 4);
        void start();
    private:
        static constexpr const char API_LIST_PREFIX[] = "/calculator/list";
        static constexpr const char API_STORE_PREFIX[] = "/calculator/store";
        static constexpr const char API_CALCULATE_PREFIX[] = "/calculator/calculate";
        static constexpr const char FILE_RESOURCE_PREFIX[] = "/res";

        static constexpr const char FILE_ROOT_DIRECTORY[] = "./dist";

        // Not exactly sure why this endpoint is shared. It was shared in the Pistache example rest_server.cc, but it
        // didn't seem to actually have a handle anywhere outside of the enclosing endpoint class.
        std::shared_ptr<Pistache::Http::Endpoint> internalEndPoint_;
        Pistache::Rest::Router router_;
        std::mutex savedExpressionsLock_;
        std::vector<calculator::expression::ExpressionSerializer<T>::ExpressionBuffer> savedExpressions_;

        void initializeRoutes();
        void initializeEndPoint(size_t threads);

        void handleApiStore(const Pistache::Rest::Request& request, Pistache::Http::ResponseWriter response);
        void handleApiList(const Pistache::Rest::Request& request, Pistache::Http::ResponseWriter response);
        void handleApiCalculate(const Pistache::Rest::Request& request, Pistache::Http::ResponseWriter response);
        void handleFileResource(const Pistache::Rest::Request& request, Pistache::Http::ResponseWriter response);
};
template<typename T>
constexpr const char CalculatorEndPoint<T>::API_LIST_PREFIX[];
template<typename T>
constexpr const char CalculatorEndPoint<T>::API_STORE_PREFIX[];
template<typename T>
constexpr const char CalculatorEndPoint<T>::API_CALCULATE_PREFIX[];
template<typename T>
constexpr const char CalculatorEndPoint<T>::FILE_RESOURCE_PREFIX[];
template<typename T>
constexpr const char CalculatorEndPoint<T>::FILE_ROOT_DIRECTORY[];

}}

#endif // #ifndef HTTPREQUESTHANDLER_H