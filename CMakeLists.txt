cmake_minimum_required(VERSION 3.5)

project(DSA LANGUAGES CXX)


# https://blog.csdn.net/z_h_s/article/details/50699905
set(CMAKE_INCLUDE_CURRENT_DIR ON)

#set(CMAKE_AUTOUIC ON)
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_COMPILER "/home/tnbs/dev-envs/GCC8.3/bin/g++")

message(STATUS "The current operating system is ${CMAKE_SYSTEM_NAME}")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake-modules")
include(base)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
if(UNIX)
    include_directories("/home/tnbs/dev-envs/GCC8.3/include")
endif(UNIX)


add_subdirectory(DSA)
add_subdirectory(qTest)
add_subdirectory(tests)


# set(${PROJECT_NAME}_LIBRARIES queue)
# compile_to_exe(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR} 1 NORECURSE)
