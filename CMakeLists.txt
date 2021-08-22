cmake_minimum_required(VERSION 3.13.4)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(
    -g
    -Wall
    -Wextra
    -pedantic
    -Werror
    -Wformat-security
    -Wduplicated-cond
    -Wfloat-equal
    -Wlogical-not-parentheses
    -Wnull-dereference
    -Wvla
    -fstack-protector-strong
    -Wunreachable-code
    -Wundef
)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

project(main)
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS src/*.cpp)
add_executable(${PROJECT_NAME} ${SRC_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC include)

find_package(SFML 2.5 COMPONENTS audio graphics window system REQUIRED)

target_link_libraries(${PROJECT_NAME} sfml-audio sfml-graphics sfml-window sfml-system)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
