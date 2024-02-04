cmake_minimum_required(VERSION 3.26.0)

set(CMAKE_TOOLCHAIN_FILE vendor/vcpkg/scripts/buildsystems/vcpkg.cmake CACHE STRING "Vcpkg toolchain file")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR} CACHE STRING "")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR} CACHE STRING "")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(Ramen VERSION 0.1.0 LANGUAGES C CXX)

file(GLOB_RECURSE SRC_FILES "src/**.cpp")
add_library(${PROJECT_NAME} SHARED ${SRC_FILES})
include_directories(src)

add_subdirectory(vendor/SDL EXCLUDE_FROM_ALL)
target_link_libraries(${PROJECT_NAME} PUBLIC SDL3::SDL3)

add_subdirectory(vendor/SDL_image EXCLUDE_FROM_ALL)
target_link_libraries(${PROJECT_NAME} PUBLIC SDL3_image::SDL3_image)

find_package(Eigen3 CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC Eigen3::Eigen)

