////////////////////////////////////////////////////////////////////////////
/**
 *  @file   main.cpp
 *  @brief  Entry Point of the rest implementation
 */
////////////////////////////////////////////////////////////////////////////

#include <iostream>

#include "CalculatorApplication.h"
#include "Rest.h"

namespace calculator {

void Rest::calculateRoute(const Pistache::Rest::Request& request, Pistache::Http::ResponseWriter response)
{
   response.headers().add<Pistache::Http::Header::AccessControlAllowOrigin>("*");
   response.headers().add<Pistache::Http::Header::ContentType>(MIME(Text, Json));
   response.headers().add<Pistache::Http::Header::AccessControlAllowMethods>("GET,POST,DELETE,PUT");
   
   calculator::CalculatorApplication calculator;

   auto result = calculator.runCalculator(request.body());
   if(!result.second)
   {
      response.send(Pistache::Http::Code::Bad_Request, "Input Incorrectly Entered");
   }
   else
   {
      response.send(Pistache::Http::Code::Ok, result.first);
   }
}

void Rest::optionsHeader(const Pistache::Rest::Request& request, Pistache::Http::ResponseWriter response)
{
   response.headers().add<Pistache::Http::Header::AccessControlAllowOrigin>("*");
   response.headers().add<Pistache::Http::Header::AccessControlAllowHeaders>("Content-Type, Authorization, Accept, Accept-Language, X-Authorization");
   response.send(Pistache::Http::Code::Ok, "Worked");
}

} //namespace calculator
