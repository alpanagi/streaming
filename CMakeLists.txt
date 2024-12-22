cmake_minimum_required(VERSION 3.31)
project(streaming)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(streaming)
target_sources(streaming PRIVATE
  src/main.cpp
)
