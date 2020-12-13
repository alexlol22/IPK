cmake_minimum_required(VERSION 3.10)

# set the project name
project(IPK4 LANGUAGES CXX)
enable_testing()

# Force compiler to run in C++14 mode
set(CMAKE_CXX_STANDARD 14)

include_directories(IPK5 PRIVATE {$YOUR_DIRECTORY})

# Create executable programs
set(HEADER_FILES io.h statistics.h)

add_library(statio io.cpp statistics.cpp ${HEADER_FILES})
target_include_directories(statio PRIVATE ${YOUR_DIRECTORY})

add_executable(readvector readvector.cpp ${HEADER_FILES})
target_link_libraries(readvector statio) 
add_executable(normal normal.cpp ${HEADER_FILES})
target_link_libraries(normal statio) 
add_executable(uniform uniform.cpp ${HEADER_FILES})
target_link_libraries(uniform statio) 

#tests are broken, not yet familiar with behaviour of ctest and bash -c
add_test(NAME EmptyInput COMMAND bash -c 'echo -e "" | ./readvector')
add_test(NAME 4Input COMMAND bash -c '[[ $(echo -e "1\n2\n3\n0.2\n\n" | ./readvector) =~ ^Mean:1.55[[:space:]]Median:1.5[[:space:]]5th[[:space:]]Moment:69.0001$ ]]')
add_test(NAME 5Input COMMAND bash -c '[[ $(echo -e "1\n2\n3\n0.2\n0.0\n\n" | ./readvector) =~ ^Mean:1.24[[:space:]]Median:1[[:space:]]5th[[:space:]]Moment:55.2001$ ]]')


