cmake_minimum_required(VERSION 3.5)

project(Webcam_OpenCV LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(Webcam_OpenCV main.cpp)

target_link_libraries(Webcam_OpenCV ${OpenCV_LIBS})
