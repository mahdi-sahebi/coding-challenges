# Options
option(BUILD_TESTS "To build the tests" ON)


# Variables
set(PUBLIC_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/include)
set(HEADERS "")
set(SOURCES test.c)
set(APP test)


# Subdirectories


# Packages


# Executables
add_executable(${APP} ${SOURCES} ${HEADERS})


# Libraries
target_link_libraries(${APP}
  PRIVATE model_counter
)

# Include Directories
target_include_directories(${APP}
  PRIVATE ${PUBLIC_INCLUDE_DIRS}
)
