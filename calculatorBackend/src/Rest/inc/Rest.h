#ifndef REST_H
#define REST_H

////////////////////////////////////////////////////////////////////////////////
/**
* @file Rest.h
* @brief rest function declarations.
*/
////////////////////////////////////////////////////////////////////////////////

#include "pistache/endpoint.h"
#include "pistache/router.h"

namespace calculator {

/**
* @brief Rest interface which exposes to other components
*/

class Rest
{
    public:
        /**
         * @brief handler for when client hits the calculate route
         * @param [in] request the pistache data needed to handle server requests
         * @param [in] response the pistache data needed to handle the response from the server
        */
        void calculateRoute(const Pistache::Rest::Request& request, Pistache::Http::ResponseWriter response);

        /**
         * @brief Tests for options to prevent browser from throwing cors error
         * @param [in] request the pistache data needed to handle server requests
         * @param [in] response the pistache data needed to handle the response from the server
        */
        void optionsTest(const Pistache::Rest::Request& request, Pistache::Http::ResponseWriter response);
};

} //namespace calculator

#endif //REST_H