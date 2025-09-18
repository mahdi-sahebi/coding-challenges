# Options


# Subdirectories


# Variables
set(PUBLIC_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/include)
set(HEADERS ${PUBLIC_INCLUDE_DIRS}/common/error.h)
set(HEADERS ${PUBLIC_INCLUDE_DIRS}/alg/alg.h)
set(HEADERS ${PUBLIC_INCLUDE_DIRS}/alg/bitarray.h)
set(SOURCES alg.c bitarray.c)
set(LIB alg)


# Packages


# Executables
add_library(${LIB} STATIC ${SOURCES} ${HEADERS})


# Libraries
target_link_libraries(${LIB} PRIVATE m storage)


# Include Directories
target_include_directories(${LIB} PUBLIC ${PUBLIC_INCLUDE_DIRS})
