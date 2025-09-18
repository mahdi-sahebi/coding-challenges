# Options


# Subdirectories


# Variables
set(PUBLIC_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/include)
set(HEADERS ${PUBLIC_INCLUDE_DIRS}/common/error.h)
set(HEADERS ${PUBLIC_INCLUDE_DIRS}/storage/file.h)
set(SOURCES file.c)
set(LIB storage)


# Packages


# Executables
add_library(${LIB} STATIC ${SOURCES} ${HEADERS})


# Libraries


# Include Directories
target_include_directories(${LIB} PUBLIC ${PUBLIC_INCLUDE_DIRS})
