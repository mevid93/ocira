include(FetchContent)

FetchContent_Declare(
  SFML
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG 3.0.0
)

FetchContent_MakeAvailable(SFML)

add_executable(sdcca src/main.cpp)
target_link_libraries(sdcca PRIVATE sfml-graphics sfml-window sfml-system)