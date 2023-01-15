cmake_minimum_required(VERSION 3.2)

project(graph)

set(CXX_STANDARD 20)

message($ENV{VCPKG_ROOT})

set(VCPKG $ENV{VCPKG_ROOT})

include_directories(${VCPKG}/installed/x86-windows/include)
link_directories(${VCPKG}/installed/x86-windows/lib)

add_executable(graph main.cpp event.h event.cpp)
target_link_libraries(graph raylib)