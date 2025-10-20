cmake_minimum_required(VERSION 3.10)
project(demo)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 查找 OpenCV 库
find_package(OpenCV PATHS ../3rd NO_DEFAULT_PATH)
find_package(OpenCV REQUIRED)

# 包含 OpenCV 头文件
include_directories(${OpenCV_INCLUDE_DIRS})


add_executable(demo
               demo.cpp
               )

# 链接 OpenCV 库
target_link_libraries(demo ${OpenCV_LIBS})
