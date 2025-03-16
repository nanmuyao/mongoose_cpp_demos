#pragma once

#include <iostream>

using namespace std;

struct Env
{   
    int port;
    string host;
    string db;
    // ...existing code...
};

// 单例模式
class AppConfig {
public:
    static AppConfig* getInstance();
    void setEnv(Env* env);
    Env* getEnv();
    void print();

    Env* env;
private:
    AppConfig();
    static AppConfig* instance;
};