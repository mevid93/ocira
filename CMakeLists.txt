cmake_minimum_required(VERSION 3.22.0)
project(sdcca VERSION 0.1.0 LANGUAGES C CXX)

# Set global C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(Core)
add_subdirectory(App)
