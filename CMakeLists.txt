cmake_minimum_required(VERSION 3.2)

project(graph)

set(CXX_STANDARD 20)

include_directories(C:/Users/pius.ogunleye/vcpkg/installed/x86-windows/include)
link_directories(C:/Users/pius.ogunleye/vcpkg/installed/x86-windows/lib)

add_executable(graph main.cpp event.h event.cpp)
target_link_libraries(graph raylib)