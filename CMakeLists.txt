cmake_minimum_required(VERSION 3.31)
project(streaming)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL3 REQUIRED)
find_package(Vulkan REQUIRED)

add_executable(streaming)
target_link_libraries(streaming
  ${SDL3_LIBRARIES}
  ${Vulkan_LIBRARIES}
)
target_sources(streaming PRIVATE
  src/main.cpp
  src/sdlk.cpp
  src/panik.cpp
  src/vlk.cpp
)
