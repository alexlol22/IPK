cmake_minimum_required(VERSION 3.5)

project(LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 14)

find_package(SDL2 REQUIRED)
include_directories(IPK11 ${SDL2_INCLUDE_DIRS})

add_executable(IPK11 main.cpp)
target_link_libraries(IPK11 ${SDL2_LIBRARIES})