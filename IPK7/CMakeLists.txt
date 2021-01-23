cmake_minimum_required(VERSION 3.10)

# set the project name
project(IPK7 LANGUAGES CXX)
enable_testing()

# Force compiler to run in C++14 mode
set(CMAKE_CXX_STANDARD 14)

include_directories(IPK7 PRIVATE {$YOUR_DIRECTORY})

add_executable(point pointMain.cpp )
add_executable(statistics statisticsDriver.cpp io.cpp )
add_executable(tests tests.cpp )
add_test(NAME Test COMMAND ./tests)
