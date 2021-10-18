cmake_minimum_required(VERSION 3.10)

# set the project name
project(lrucache)

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

# target_link_libraries(lrucache lrucache.cc doubly_list.cc main.cc)
add_library(lrucache lrucache.cc doubly_list.cc)

# add the executable
# add_executable(lrucache lrucache.cc doubly_list.cc)

# build test
enable_testing()

 add_executable(
  lru_test
  lru_test.cc
)

target_link_libraries(
  lru_test
  lrucache
  gtest_main
)