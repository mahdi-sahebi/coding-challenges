# Options


# Variables
set(PUBLIC_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(PUBLIC_LIBRARY_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(YAJL_LIBRARIES 
  ${PUBLIC_LIBRARY_DIRS}/libyajl.so
  ${PUBLIC_LIBRARY_DIRS}/libyajl.so.2
  ${PUBLIC_LIBRARY_DIRS}/libyajl.so.2.1.1
  ${PUBLIC_LIBRARY_DIRS}/libyajl_s.a
)
set(LIB yajl_s)


# Subdirectories
add_library(${LIB} INTERFACE)


# Packages


# Executables


# Libraries
target_link_libraries(${LIB}
  INTERFACE ${YAJL_LIBRARIES}
)


# Include Directories
target_include_directories(${LIB} 
  INTERFACE ${PUBLIC_INCLUDE_DIRS}
)