#pragma once

#include <map>
#include <string>
#include <mutex>
#include <memory>
#include <mongoose/Controller.h>

using namespace std;
using namespace Mongoose;

template <typename T>
class ControllerMgr
{
private:
    map<string, shared_ptr<T>> controllers;
    mutex mtx;

    ControllerMgr();
    ~ControllerMgr();

public:
    static ControllerMgr& getInstance();

    shared_ptr<T> getController(const string& name);

    void registerController(const string& name, shared_ptr<T> controller);

    void registerRoute(const string& controllerName, const string& httpMethod, const string& route, RequestHandlerBase* handler);

    vector<string> getControllerNames();

    vector<shared_ptr<T>> getControllers();

    // 禁止拷贝和赋值
    ControllerMgr(const ControllerMgr&) = delete;
    ControllerMgr& operator=(const ControllerMgr&) = delete;
};
