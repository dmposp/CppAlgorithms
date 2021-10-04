cmake_minimum_required(VERSION 3.10)

# set the project name
project(LRUCache)

# set C++ version
set(CMAKE_CXX_STANDARD 11)

# Google test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# target_link_libraries(LRUCache LRUCache.cpp Node.cpp main.cpp)
add_library(LRUCache LRUCache.cpp Node.cpp)

# add the executable
# add_executable(LRUCache LRUCache.cpp Node.cpp)

# build test
enable_testing()

 add_executable(
  LRUTest
  LRUTest.cpp
)

target_link_libraries(
  LRUTest
  LRUCache
  gtest_main
)