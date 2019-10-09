cmake_minimum_required(VERSION 3.15)
project(tp1 C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mavx2") # Add `-mavx2` flag to compilation (access to _mm256 functions)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mfma") # Add `-mfma` flag to compilation (access to fma functions)

add_executable(tp1 main.c intrinsicsIntel.c intrinsicsIntel.h displayUtils.c displayUtils.h intrinsicsGcc.c intrinsicsGcc.h)