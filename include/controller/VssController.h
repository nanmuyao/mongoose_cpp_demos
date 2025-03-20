#pragma once

#include <mongoose/WebController.h> // Ensure this path is correct and the file exists
#include <mongoose/Request.h>
#include <mongoose/StreamResponse.h>

using namespace Mongoose;

class VssController : public WebController
{
public:
    VssController();
    ~VssController();
    
    void setup();
    void hello(Request &request, StreamResponse &response);
    void foo();
};

