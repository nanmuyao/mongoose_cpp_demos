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
    cout << "start server 11 ..." << endl;
    cout << "start server 22 ..." << endl;
    // 初始化配置
    AppConfig* appConfig = AppConfig::getInstance();
    cout << "AppConfig instance obtained" << endl; // 添加调试输出
    cout << "start server ... appConfig->env->port: " << appConfig->env->port << endl;
    
    // VssController vssController;

    // 使用ControllerMgr管理Controller
    ControllerMgr& controllerMgr = ControllerMgr::getInstance();
    cout << "ControllerMgr instance obtained" << endl; // 添加调试输出
    controllerMgr.init();

    // cout << "controllerMgr init" << endl;

    // Server server(appConfig->env->port);
    // cout << "Server server(appConfig->env->port)" << endl;
    // // server.registerController(controller.get());
    // server.registerController(controllerMgr.controllerMap.vss_controller.get());
    // cout << "server.registerController(controllerMgr.controllerMap.vss_controller.get())" << endl;  
    
    // server.start(); 
    // cout << "server.start()" << endl;

    // while (1) {
    //     sleep(1);
    // }
    // cout << "down server on port 8080" << endl;
    return 0;
}