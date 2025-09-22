# Options


# Variables
set(PUBLIC_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/include)
set(HEADERS ${PUBLIC_INCLUDE_DIRS}/model.h)
set(SOURCES model.c)
set(LIB model)


# Subdirectories


# Packages


# Executables
add_library(${LIB} STATIC ${SOURCES} ${HEADERS})


# Libraries


# Include Directories

