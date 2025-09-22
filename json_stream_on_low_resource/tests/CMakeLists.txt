# Options
option(BUILD_TESTS "To build the tests" ON)


# Variables
set(HEADERS "")
set(SOURCES test.c)
set(APP test)


# Subdirectories


# Packages


# Executables
add_executable(${APP} ${SOURCES} ${HEADERS})


# Libraries
target_link_libraries(${APP}
  PRIVATE model
)
