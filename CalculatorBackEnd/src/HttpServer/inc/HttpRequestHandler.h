////////////////////////////////////////////////////////////////////////////////
/**
 * @file HttpRequestHandler.h
 * @date Wed March 16 2022
 * @brief header for a class that handles the HTTP requests for the server
 */
////////////////////////////////////////////////////////////////////////////////

#include <pistache/http.h>

//#include "ExpressionSerializer.h"


namespace calculator { namespace httpserver
{

/**
 * @brief a class for handling HTTP requests of all types, from 
 */
class HttpRequestHandler : public Pistache::Http::Handler
{
    public:
        HTTP_PROTOTYPE(HttpRequestHandler)
        void onRequest(const Pistache::Http::Request& req, Pistache::Http::ResponseWriter response) override;
    private:
        static constexpr const char *API_PREFIX = "/api/";
        static constexpr const char *API_LIST_PREFIX = "list";
        static constexpr const char *API_STORE_PREFIX = "store";
        static constexpr const char *API_CALCULATE_PREFIX = "calculate";
        static constexpr const char *FILE_ROOT_DIRECTORY = "./dist";
};
constexpr const char *HttpRequestHandler::API_PREFIX;
constexpr const char *HttpRequestHandler::API_LIST_PREFIX;
constexpr const char *HttpRequestHandler::API_STORE_PREFIX;
constexpr const char *HttpRequestHandler::API_CALCULATE_PREFIX;
constexpr const char *HttpRequestHandler::FILE_ROOT_DIRECTORY;

}}