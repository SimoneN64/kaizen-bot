cmake_minimum_required(VERSION 3.20)
project(kaizen-bot CXX)

add_executable(kaizen-bot src/main.cpp)
target_include_directories(kaizen-bot PUBLIC src)