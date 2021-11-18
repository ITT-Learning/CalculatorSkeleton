////////////////////////////////////////////////////////////////////////////
/**
 *  @file   main.cpp
 *  @brief  Entry Point of the rest implementation
 */
////////////////////////////////////////////////////////////////////////////

#include "pistache/endpoint.h"
#include "pistache/router.h"
#include "Rest.h"

#include <iostream>

int main()
{
   Pistache::Rest::Router router;
   calculator::Rest rest;

   Pistache::Rest::Routes::Post(router, "/calculate", Pistache::Rest::Routes::bind(&calculator::Rest::calculateRoute, &rest));
   Pistache::Rest::Routes::Options(router, "/calculate", Pistache::Rest::Routes::bind(&calculator::Rest::optionsTest, &rest));
   Pistache::Address addr(Pistache::Ipv4::any(), Pistache::Port(9080));
   Pistache::Http::Endpoint server(addr);
   server.init(Pistache::Http::Endpoint::options().threads(1).flags(Pistache::Tcp::Options::ReusePort));
   server.setHandler(router.handler());
   server.serve();
}