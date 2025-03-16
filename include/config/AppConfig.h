#pragma once

#include <iostream>

using namespace std;

struct env
{   
    int port;
    string host;
    string db;
    /* data */
};

// 单例模式
class AppConfig {
public:
    static AppConfig* getInstance();
    void setEnv(env* env);
    env* getEnv();
    void print();

    env* env;
private:
    AppConfig();
    static AppConfig* instance;
};