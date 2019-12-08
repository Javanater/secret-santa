cmake_minimum_required(VERSION 3.2)

project(secret-santa)

add_subdirectory(convenience)

add_executable(demo demo.cpp)

target_link_libraries(demo PRIVATE convenience)

