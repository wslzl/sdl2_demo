cmake_minimum_required(VERSION 3.23)

set(PROJECT_NAME sdl_demo)

project(${PROJECT_NAME} C)

set(CMAKE_C_STANDARD 99)

set( SDL_STATIC OFF CACHE BOOL "" FORCE )
set( SDL_SHARED ON CACHE BOOL "" FORCE )

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/dist)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/dist)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/dist)

add_subdirectory(third_party/SDL)

link_directories(${PROJECT_BINARY_DIR}/dist)

add_executable(${PROJECT_NAME} main.c)

#target_link_libraries(${PROJECT_NAME} PRIVATE mingw32 SDL2-static SDL2main)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2main SDL2)
