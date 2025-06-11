cmake_minimum_required(VERSION 3.30)
project(apm)

set(CMAKE_CXX_STANDARD 20)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include_directories(
        ${CMAKE_SOURCE_DIR}/include
)

add_subdirectory(src)
