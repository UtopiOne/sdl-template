cmake_minimum_required(VERSION 3.2)
project(game_programming)

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_BUILD_TYPE Debug)

IF (CMAKE_BUILD_TYPE MATCHES Debug)
    message("Debug build.")
ENDIF()

find_package(SDL2 REQUIRED)
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR} ${SDL2_INCLUDE_DIRS})

file(GLOB SOURCE_FILES 
    ${PROJECT_SOURCE_DIR}/src/*.cpp
    ${PROJECT_SOURCE_DIR}/src/Components/*.cpp
    ${PROJECT_SOURCE_DIR}/src/Actors/*.cpp
    ${PROJECT_SOURCE_DIR}/src/Helpers/*.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} SDL2 SDL2_image)
