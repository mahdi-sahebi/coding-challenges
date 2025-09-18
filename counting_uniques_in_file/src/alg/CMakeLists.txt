# Options


# Subdirectories


# Variables
set(PUBLIC_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/include)
set(HEADERS ${PUBLIC_INCLUDE_DIRS}/alg/alg.h)
set(SOURCES alg.c)
set(LIB alg)


# Packages


# Executables
add_library(alg STATIC ${SOURCES} ${HEADERS})


# Libraries


# Include Directories
target_include_directories(${LIB} PUBLIC ${PUBLIC_INCLUDE_DIRS})
