#ifndef _CALCULATOR_REST_H
#define _CALCULATOR_REST_H

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
         * @brief function to add Option response headers
         * @param [in] request request sent by browser
         * @param [in] response response to be sent by Api back to browser
         */
        void optionsHeader(const Pistache::Rest::Request& request, Pistache::Http::ResponseWriter response);

        /**
         * @brief handler for when client hits the calculate route
         * @param [in] request request sent by browser
         * @param [in] response response to be sent by Api back to browser
        */
        void calculateRoute(const Pistache::Rest::Request& request, Pistache::Http::ResponseWriter response);
};

} //namespace calculator

#endif //_CALCUALTOR_REST_H
