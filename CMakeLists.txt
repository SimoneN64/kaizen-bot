cmake_minimum_required(VERSION 3.20)
project(kaizen-bot CXX)

add_subdirectory(externals/DPP)

find_package(fmt REQUIRED)

add_executable(kaizen-bot src/main.cpp)
target_include_directories(kaizen-bot PUBLIC src)
target_link_libraries(kaizen-bot PUBLIC dpp fmt)
set_target_properties(kaizen-bot PROPERTIES CXX_STANDARD 20)