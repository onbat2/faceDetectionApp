cmake_minimum_required(VERSION 3.5)

project(face_detection LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(face_detection main.cpp)
target_link_libraries(face_detection ${OpenCV_LIBS})
