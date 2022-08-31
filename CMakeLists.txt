cmake_minimum_required(VERSION 3.13.0)

project(so_test)

add_library(vt_test SHARED vtable.cpp)

add_executable(caller caller.cpp)
target_link_libraries(caller dl)
