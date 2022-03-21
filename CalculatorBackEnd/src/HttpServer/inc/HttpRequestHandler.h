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

#include <flatbuffers/idl.h>
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
        using VariableAssignments = std::map<char, T>;

        struct RoutingConstants
        {
            static constexpr const char ROUTE_LIST[] = "/calculator/list";
            static constexpr const char ROUTE_STORE[] = "/calculator/store";
            static constexpr const char ROUTE_CALCULATE[] = "/calculator/calculate";
        };

        struct JsonConstants
        {
            struct RequestTypes
            {
                static constexpr const char STORE[] = "storeRequest";
                static constexpr const char LIST[] = "listRequest";
                static constexpr const char CALCULATE[] = "calculateRequest";
            };
            struct ResponseTypes
            {
                static constexpr const char STORE[] = "storeResponse";
                static constexpr const char LIST[] = "listResponse";
                static constexpr const char CALCULATE[] = "calculateResponse";
            };
            struct DataKeys
            {
                struct ExpressionKeys
                {
                    static constexpr const char ID[] = "id";
                    static constexpr const char STRING[] = "string";
                    static constexpr const char VALUE[] = "value";
                    static constexpr const char VARIABLES[] = "variables";
                };
                static constexpr const char EXPRESSION[] = "expression";
                static constexpr const char EXPRESSIONS[] = "expressions";
                static constexpr const char SUCCESSFUL[] = "successful";
            };
            static constexpr const char REQUESTTYPE_KEY[] = "requestType";
            static constexpr const char REQUESTDATA_KEY[] = "requestData";

            static constexpr const char RESPONSETYPE_KEY[] = "responseType";
            static constexpr const char RESPONSEDATA_KEY[] = "responseData";
        };
        static constexpr const char FILE_ROOT_DIRECTORY[] = "./dist";

        nlohmann::json expressionToJson(std::size_t id, boost::optional<const VariableAssignments &> variableAssignments);

        // Not exactly sure why this endpoint is shared. It was shared in the Pistache example rest_server.cc, but it
        // didn't seem to actually have a handle anywhere outside of the enclosing endpoint class.
        std::shared_ptr<Pistache::Http::Endpoint> internalEndPoint_;
        Pistache::Rest::Router router_;
        std::mutex savedExpressionsLock_;
        std::vector<typename calculator::expression::ExpressionSerializer<T>::ExpressionBuffer> savedExpressions_;

        void initializeRoutes();
        void initializeEndPoint(size_t threads);

        Pistache::Rest::Route::Result handleApiStore(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response);
        Pistache::Rest::Route::Result handleApiList(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response);
        Pistache::Rest::Route::Result handleApiCalculate(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response);
        static Pistache::Rest::Route::Result handleFileResource(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response);
};
template<typename T>
constexpr const char CalculatorEndPoint<T>::RoutingConstants::ROUTE_LIST[];
template<typename T>
constexpr const char CalculatorEndPoint<T>::RoutingConstants::ROUTE_STORE[];
template<typename T>
constexpr const char CalculatorEndPoint<T>::RoutingConstants::ROUTE_CALCULATE[];
template<typename T>
constexpr const char CalculatorEndPoint<T>::JsonConstants::RequestTypes::STORE[];
template<typename T>
constexpr const char CalculatorEndPoint<T>::JsonConstants::RequestTypes::LIST[];
template<typename T>
constexpr const char CalculatorEndPoint<T>::JsonConstants::RequestTypes::CALCULATE[];
template<typename T>
constexpr const char CalculatorEndPoint<T>::JsonConstants::ResponseTypes::STORE[];
template<typename T>
constexpr const char CalculatorEndPoint<T>::JsonConstants::ResponseTypes::LIST[];
template<typename T>
constexpr const char CalculatorEndPoint<T>::JsonConstants::ResponseTypes::CALCULATE[];
template<typename T>
constexpr const char CalculatorEndPoint<T>::JsonConstants::DataKeys::ExpressionKeys::ID[];
template<typename T>
constexpr const char CalculatorEndPoint<T>::JsonConstants::DataKeys::ExpressionKeys::STRING[];
template<typename T>
constexpr const char CalculatorEndPoint<T>::JsonConstants::DataKeys::ExpressionKeys::VALUE[];
template<typename T>
constexpr const char CalculatorEndPoint<T>::JsonConstants::DataKeys::ExpressionKeys::VARIABLES[];
template<typename T>
constexpr const char CalculatorEndPoint<T>::JsonConstants::DataKeys::EXPRESSION[];
template<typename T>
constexpr const char CalculatorEndPoint<T>::JsonConstants::DataKeys::EXPRESSIONS[];
template<typename T>
constexpr const char CalculatorEndPoint<T>::JsonConstants::DataKeys::SUCCESSFUL[];
template<typename T>
constexpr const char CalculatorEndPoint<T>::JsonConstants::REQUESTTYPE_KEY[];
template<typename T>
constexpr const char CalculatorEndPoint<T>::JsonConstants::REQUESTDATA_KEY[];
template<typename T>
constexpr const char CalculatorEndPoint<T>::JsonConstants::RESPONSETYPE_KEY[];
template<typename T>
constexpr const char CalculatorEndPoint<T>::JsonConstants::RESPONSEDATA_KEY[];
template<typename T>
constexpr const char CalculatorEndPoint<T>::FILE_ROOT_DIRECTORY[];

}}

#endif // #ifndef HTTPREQUESTHANDLER_H