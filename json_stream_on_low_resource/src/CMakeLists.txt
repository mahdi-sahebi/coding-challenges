# Options


# Variables
set(PUBLIC_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/include)
SET(PRIVATE_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/deps/yajl/src/api)
set(HEADERS ${PUBLIC_INCLUDE_DIRS}/model/model.h
# ${PRIVATE_INCLUDE_DIRS}/yajl/src/apiyajl_parser.h
)
set(SOURCES model.c)
set(LIB model)


# Subdirectories


# Packages


# Executables
add_library(${LIB} STATIC ${SOURCES} ${HEADERS})


# Libraries
target_link_libraries(${LIB}
  PRIVATE yajl_s
)


# Include Directories
target_include_directories(${LIB}
  PUBLIC  ${PUBLIC_INCLUDE_DIRS}
  PRIVATE ${PRIVATE_INCLUDE_DIRS}
)
