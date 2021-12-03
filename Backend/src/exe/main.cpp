////////////////////////////////////////////////////////////////////////////
/**
 *  @file   main.cpp
 *  @date   Fri August 25 2021
 *  @brief  This is a basic calculator program which asks for an equation and uses a switch to decifer what the equation is and return the result
 */
////////////////////////////////////////////////////////////////////////////

#include "Rest.h"

using namespace calculator;

/**
 * @brief Main interface which exposes to other components
 *
 */

int main() 
{
    std::cout << "Starting Server" << std::endl;
    Pistache::Rest::Router router;
    calculator::Rest rest; 
    
    auto test = Pistache::Rest::Routes::bind(&calculator::Rest::calculatePost, &rest);
    Pistache::Rest::Routes::Post(router, "/calculate", test);
    auto optionsHeader = Pistache::Rest::Routes::bind(&calculator::Rest::optionsHeader, &rest);

    Pistache::Rest::Routes::Options(router, "/calculate", optionsHeader);

    Pistache::Address addr(Pistache::Ipv4::any(), Pistache::Port(9080));
    auto opts = Pistache::Http::Endpoint::options().threads(1).flags(Pistache::Tcp::Options::ReusePort);
    Pistache::Http::Endpoint server(addr);
    server.init(opts);
    server.setHandler(router.handler());
    server.serve();

} // namespace calculator
