#----------------------------------------------------------------------------
# Core library
#----------------------------------------------------------------------------
file(GLOB CORE_SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_library(ocira_core "${CORE_SRC_FILES}")

target_include_directories(ocira_core PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

message(STATUS "Armadillo include path: ${armadillo_SOURCE_DIR}/include")

target_include_directories(ocira_core PUBLIC ${armadillo_SOURCE_DIR}/include)
find_library(ARMADILLO_LIB armadillo PATHS ${armadillo_BINARY_DIR} NO_DEFAULT_PATH)
target_link_libraries(ocira_core PRIVATE ${ARMADILLO_LIB})



#----------------------------------------------------------------------------
# Core library tests
#----------------------------------------------------------------------------
if (BUILD_TESTING)
    enable_testing()

    include(GoogleTest)

    file(GLOB CORE_TEST_FILES "${CMAKE_CURRENT_SOURCE_DIR}/test/*.cpp")

    add_executable(core_tests "${CORE_TEST_FILES}")

    target_link_libraries(core_tests PRIVATE gtest_main)

    target_link_libraries(core_tests PRIVATE ocira_core)

    gtest_discover_tests(core_tests)
endif()