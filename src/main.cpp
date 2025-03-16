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

using namespace std;
using namespace Mongoose;


int main()
{
    cout << "Starting server on port 8080" << endl;
    // 初始化配置
    AppConfig* appConfig = AppConfig::getInstance();
    cout << "appConfig->env->port: " << appConfig->env->port << endl;
    VssController vssController;
    Server server(8080);
    server.registerController(&vssController);

    server.start(); 
    while (1) {
        sleep(10);
    }
    cout << "down server on port 8080" << endl;
}