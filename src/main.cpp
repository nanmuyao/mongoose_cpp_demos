#include <stdlib.h>
#include <signal.h>
#include <mongoose/Server.h>
#include <mongoose/WebController.h>
#include <thread>
#include <chrono>
#include <unistd.h>
#include <json/json.h>

#include "VssController.h"
#include "AppConfig.h"
#include <ControllerMgr.h>

using namespace std;
using namespace Mongoose;

// 求和计算


int main()
{
    cout << "Starting server on port 8080" << endl;
    // 初始化配置
    AppConfig* appConfig = AppConfig::getInstance();
    cout << "appConfig->env->port: " << appConfig->env->port << endl;
    
    // VssController vssController;

    // 使用ControllerMgr管理Controller
    ControllerMgr<Controller>& controllerMgr = ControllerMgr<Controller>::getInstance();
    shared_ptr<VssController> vssController = make_shared<VssController>();
    controllerMgr.registerController("vss", vssController);
    vssController->setup();

    Server server(appConfig->env->port);
    // 遍历ControllerMgr中的Controller
    vector<shared_ptr<Controller>> controllers = controllerMgr.getControllers();
    for (auto& controller : controllers) {
        server.registerController(controller.get());
    }
    // server.registerController(&vssController);

    server.start(); 
    while (1) {
        sleep(10);
    }
    cout << "down server on port 8080" << endl;
}