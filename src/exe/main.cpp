////////////////////////////////////////////////////////////////////////////
/**
 *  @file   main.cpp
 *  @date   Fri August 25 2021
 *  @brief  This is a basic calculator program which asks for an equation and uses a switch to decifer what the equation is and return the result
 */
////////////////////////////////////////////////////////////////////////////

// #include "CalculatorApplication.h"
// #include "CalculatorStrings.h"
// #include "History.h"
// #include "Parser.h"
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
    
    // this bind thing is where I am binding this function to the route, that is why it is called when arriving
    auto test = Pistache::Rest::Routes::bind(&calculator::Rest::calculateRoute, &rest);
    Pistache::Rest::Routes::Post(router, "/calculate", test);
    auto optionsTest = Pistache::Rest::Routes::bind(&calculator::Rest::optionsHeader, &rest);

    Pistache::Rest::Routes::Options(router, "/calculate", optionsTest);

    Pistache::Address addr(Pistache::Ipv4::any(), Pistache::Port(9080));
    auto opts = Pistache::Http::Endpoint::options().threads(1).flags(Pistache::Tcp::Options::ReusePort);
    Pistache::Http::Endpoint server(addr);
    server.init(opts);
    server.setHandler(router.handler());
    server.serve();

    
    
} // namespace calculator
