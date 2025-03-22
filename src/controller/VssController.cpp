#include <iostream>
#include <mongoose/Controller.h>
#include "VssController.h"

using namespace std;
using namespace Mongoose;

VssController::VssController() {
    // 构造函数的实现
}

VssController::~VssController() {
    // 析构函数的实现
}

void VssController::setup() {
    addRoute("GET", "/vss", VssController, hello);
    addRoute("GET", "/vss/hello", VssController, hello);
}

void VssController::foo() {
    cout << "foo func" << endl;   // do something
}

void VssController::hello(Request &request, StreamResponse &response) {
    foo();  

    cout << "hello() method called" << endl;
    cout.flush();
    response << "Hello 111" << htmlEntities(request.get("name", "... what's your name ?111")) << endl;
}

// void VssController::preProcess(Request &request, Response &response)
// {
//     cout << "VssController::preProcess" << endl;
// }
        
// void VssController::postProcess(Request &request, Response &response)
// {
//     cout << "VssController::postProcess" << endl;
// }