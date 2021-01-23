cmake_minimum_required(VERSION 3.10)

# set the project name
project(IPK6 LANGUAGES CXX)
enable_testing()

# Force compiler to run in C++14 mode
set(CMAKE_CXX_STANDARD 14)

include_directories(IPK6 PRIVATE {$YOUR_DIRECTORY})

# Create executable programs
set(HEADER_FILES canvas.h pgm.h point.h polygon.h)

add_library(stuff canvas.cpp pgm.cpp point.cpp polygon.cpp ${HEADER_FILES})
target_include_directories(stuff PRIVATE ${YOUR_DIRECTORY})

add_executable(poly poly.cpp)
target_link_libraries(poly stuff) 
add_executable(plot plot.cpp)
target_link_libraries(plot stuff)
