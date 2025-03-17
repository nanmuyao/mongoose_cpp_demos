#include "ControllerMgr.h"

ControllerMgr::ControllerMgr() {}

ControllerMgr::~ControllerMgr() {}

void ControllerMgr::init() {
    // 初始化Controller
    controllerMap.vss_controller = make_shared<VssController>();
    controllerMap.vss_controller->setup();
}

ControllerMgr& ControllerMgr::getInstance() {
    static ControllerMgr instance;
    return instance;
}