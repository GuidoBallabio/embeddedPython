cmake_minimum_required(VERSION 3.0.0)
project(main VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(main main.cpp)

target_include_directories(main PRIVATE .)

set(CMAKE_BUILD_TYPE Debug)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
