# 声明cmake最低版本
cmake_minimum_required(VERSION 2.6)

# 添加c++11标准支持
set(CMAKE_CXX_FLAGS "--std=c++14")

# 声明cmake工程
project(mythread)

# 头文件
include_directories(${PROJECT_SOURCE_DIR}/include)

# 通过设定SRC变量， 将源代码路径都给SRC， 如果有多个可以直接在后面添加
set(SRC
${PROJECT_SOURCE_DIR}/src/thread_base.cpp
${PROJECT_SOURCE_DIR}/src/thread_executor.cpp
${PROJECT_SOURCE_DIR}/src/mythread.cpp
${PROJECT_SOURCE_DIR}/src/thread_pool.cpp
${PROJECT_SOURCE_DIR}/src/task.cpp
${PROJECT_SOURCE_DIR}/src/msg_server.cpp
)

# 创建共享库/静态库
# 设置路径
set(CMAKE_LIBRARY_OUTPU_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(LIB_NAME mythrad)
add_library(${LIB_NAME} STATIC ${SRC})

# 链接库文件
target_link_libraries(${LIB_NAME} pthread dl)

# 编译主函数，生成可执行文件
# 设置编译生成路径
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)


# 生成可执行文件
add_executable(${PROJECT_NAME} ${SRC})

# 这个可执行文件所需的库
target_link_libraries(${PROJECT_NAME} pthread dl ${LIB_NAME})



