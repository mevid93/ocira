cmake_minimum_required(VERSION 3.22.0)
project(ocira VERSION 0.1.0 LANGUAGES C CXX)

# Set global C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fetch Google test module
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# Fetch Armadillo library
FetchContent_Declare(
  armadillo
  GIT_REPOSITORY https://gitlab.com/conradsnicta/armadillo-code.git
  GIT_TAG        14.6.2
)

FetchContent_MakeAvailable(armadillo)

if (BUILD_TESTING)
    enable_testing()
endif()

add_subdirectory(Core)
add_subdirectory(App)
