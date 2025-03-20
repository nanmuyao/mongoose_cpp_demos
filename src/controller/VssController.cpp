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
    addRoute("GET", "/hello", VssController, hello);
}

void VssController::foo() {
    cout << "foo func" << endl;   // do something
}

void VssController::hello(Request &request, StreamResponse &response) {
    foo();  
    response << "Hello " << htmlEntities(request.get("name", "... what's your name ?")) << endl;
}