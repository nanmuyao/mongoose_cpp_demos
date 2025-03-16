#include "ControllerMgr.h"

template <typename T>
ControllerMgr<T>::ControllerMgr() {}

template <typename T>
ControllerMgr<T>::~ControllerMgr() {}

template <typename T>
ControllerMgr<T>& ControllerMgr<T>::getInstance() {
    static ControllerMgr<T> instance;
    return instance;
}

template <typename T>
shared_ptr<T> ControllerMgr<T>::getController(const string& name) {
    lock_guard<mutex> lock(mtx);
    if (controllers.find(name) != controllers.end()) {
        return controllers[name];
    }
    return nullptr;
}

template <typename T>
void ControllerMgr<T>::registerController(const string& name, shared_ptr<T> controller) {
    lock_guard<mutex> lock(mtx);
    controllers[name] = controller;
}

template <typename T>
void ControllerMgr<T>::registerRoute(const string& controllerName, const string& httpMethod, const string& route, RequestHandlerBase* handler) {
    lock_guard<mutex> lock(mtx);
    if (controllers.find(controllerName) != controllers.end()) {
        controllers[controllerName]->registerRoute(httpMethod, route, handler);
    }
}

template <typename T>
vector<string> ControllerMgr<T>::getControllerNames() {
    lock_guard<mutex> lock(mtx);
    vector<string> names;
    for (auto& pair : controllers) {
        names.push_back(pair.first);
    }
    return names;
}

template <typename T>
vector<shared_ptr<T>> ControllerMgr<T>::getControllers() {
    lock_guard<mutex> lock(mtx);
    vector<shared_ptr<T>> controllerList;
    for (auto& pair : controllers) {
        controllerList.push_back(pair.second);
    }
    return controllerList;
}
