cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Define the path to the configuration file
set(SOLUTION_DIR "${CMAKE_SOURCE_DIR}/")

# Pass the path as a preprocessor definition
add_compile_definitions(SOLUTION_DIR="${SOLUTION_DIR}")

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(
    main src/main.cpp
    
    "src/Game.cpp"
    "lib/Game.hpp"

    "States/State.cpp"
    "States/State.hpp"

    "States/GameState.cpp"
    "States/GameState.hpp"

    "Entities/Entity.cpp"
    "Entities/Entity.hpp"

)

target_link_libraries(main PRIVATE SFML::Graphics SFML::Audio SFML::Network)