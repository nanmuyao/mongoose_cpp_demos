rm -rf build
mkdir build && cd build
cmake ..
make -j8

echo "pwd==: ${PWD}"

cp ../app_config.json ./

# 启动服务器（后台运行）
./mongoose_cpp_demos &

# 在另一个终端中测试服务器
curl http://localhost:8080/hello

# 停止服务器
kill %1