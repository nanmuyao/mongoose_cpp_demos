#pragma once

#include <map>
#include <string>
#include <mutex>
#include <memory>
#include <mongoose/Controller.h>
#include "VssController.h"

using namespace std;
using namespace Mongoose;

struct ControllerMap {
    std::shared_ptr<VssController> vss_controller;
};

class ControllerMgr
{
private:
    // map<string, shared_ptr<T>> controllers;
    mutex mtx;

    ControllerMgr();
    ~ControllerMgr();

public:
    static ControllerMgr& getInstance();

    void init();

    // 禁止拷贝和赋值
    ControllerMgr(const ControllerMgr&) = delete;
    ControllerMgr& operator=(const ControllerMgr&) = delete;

    ControllerMap controllerMap;
};
