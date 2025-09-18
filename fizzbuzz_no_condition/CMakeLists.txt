# Configuration
cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
project(fizzbuzz LANGUAGES C VERSION 1.0.0)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)


# Options


# Subdirectories


# Variables
set(PUBLIC_INCLUDE_DIRS ${PROJECT_SOURCE_DIR})
set(HEADERS ${PUBLIC_INCLUDE_DIRS}/include/types.h)
set(SOURCES src/fizzbuzz.c src/main.c)
set(APP fizzbuzz)


# Packages


# Executables
add_executable(${APP} ${SOURCES} ${HEADERS})


# Libraries


# Include Directories
target_include_directories(${APP} PRIVATE ${PUBLIC_INCLUDE_DIRS})