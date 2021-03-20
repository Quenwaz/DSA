cmake_minimum_required(VERSION 3.5)

project(DSA LANGUAGES CXX)


# https://blog.csdn.net/z_h_s/article/details/50699905
set(CMAKE_INCLUDE_CURRENT_DIR ON)

#set(CMAKE_AUTOUIC ON)
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake-modules")
include(base)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})


add_subdirectory(queue)
add_subdirectory(binarysearch)
