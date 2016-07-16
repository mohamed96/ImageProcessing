cmake_minimum_required(VERSION 3.5)
project(ImageProcessing)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp ImageProcessing.h RGBPixel.cpp RGBPixel.h Image.cpp Image.h Note.h)
add_executable(ImageProcessing ${SOURCE_FILES})
add_library(core ${SOURCE_FILES})
add_subdirectory(Test)
target_link_libraries(ImageProcessing core)