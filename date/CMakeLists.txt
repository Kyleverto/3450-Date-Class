cmake_minimum_required(VERSION 3.10.0)
project(date VERSION 0.1.0 LANGUAGES C CXX)

add_library(date date.cpp)
target_include_directories(date PUBLIC
    "."
)

