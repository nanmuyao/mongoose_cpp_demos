#!/bin/bash

set -e  # 遇到错误立即退出

# 清理并创建 build 目录
if [ -d "build" ]; then
    rm -rf build
fi
mkdir build && cd build

# 运行 CMake 和编译
cmake -DCMAKE_BUILD_TYPE=Debug .. || { echo "CMake 失败"; exit 1; }
make -j$(nproc) || { echo "编译失败"; exit 1; }

# 打印当前路径
echo "pwd==: ${PWD}"

# 复制配置文件
cp ../app_config.json ./

# 启动服务器（后台运行）
./mongoose_cpp_demos
SERVER_PID=$!
echo "服务器已启动，PID: $SERVER_PID"

# 等待 2 秒，确保服务器启动
sleep 5

# 测试服务器
# echo "curl http://localhost:8090/hello =========="
# curl http://localhost:8090/hello || { echo "服务器未正确响应"; exit 1; }

# 停止服务器
# echo "停止服务器（PID: $SERVER_PID）"
# kill $SERVER_PID
