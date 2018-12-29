find_path(
  TooN_INCLUDE_DIR
  NAMES TooN/TooN.h
  PATH_SUFFIXES include
)

find_package(
  LAPACK
  REQUIRED
)

add_library(
  TooN
  INTERFACE
)

target_include_directories(
  TooN
  SYSTEM INTERFACE
  ${TooN_INCLUDE_DIR}
)

target_link_libraries(
  TooN
  INTERFACE 
  ${LAPACK_LIBRARIES}
  #-lblas
)

add_library(
  TooN::TooN
  ALIAS
  TooN
)
