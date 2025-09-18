# Options
option(BUILD_TESTS "To compile test files" ON)
if (NOT BUILD_TESTS)
  return()
endif()


# Subdirectories


# Variables
set(PUBLIC_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/include)
set(HEADERS "")
set(SOURCES test.c)
set(TEST test)


# Packages


# Executables
add_executable(${TEST} ${SOURCES} ${HEADERS})


# Libraries
target_link_libraries(${TEST} PRIVATE alg)


# Include Directories


