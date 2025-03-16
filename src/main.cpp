#include <stdlib.h>
#include <signal.h>
#include <mongoose/Server.h>
#include <mongoose/WebController.h>
#include <thread>
#include <chrono>
#include <unistd.h>

using namespace std;
using namespace Mongoose;

class MyController : public WebController
{
    public: 
        void hello(Request &request, StreamResponse &response)
        {
            response << "Hello " << htmlEntities(request.get("name", "... what's your name ?")) << endl;
        }

        void setup()
        {
            addRoute("GET", "/hello", MyController, hello);
        }
};


int main()
{
    int a = 1;
    cout << "Starting server on port 8080" << endl;
    MyController myController;
    Server server(8080);
    server.registerController(&myController);

    server.start(); 
    while (1) {
        sleep(10);
    }
    cout << "down server on port 8080" << endl;
}