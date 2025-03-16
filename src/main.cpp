#include <stdlib.h>
#include <signal.h>
#include <mongoose/Server.h>
#include <mongoose/WebController.h>
#include <thread>
#include <chrono>
#include <unistd.h>

#include "VssController.h"
#include "AppConfig.h"

using namespace std;
using namespace Mongoose;


int main()
{
    int a = 1;
    cout << "Starting server on port 8080" << endl;
    VssController vssController;
    Server server(8080);
    server.registerController(&vssController);

    server.start(); 
    while (1) {
        sleep(10);
    }
    cout << "down server on port 8080" << endl;
}