find_path(
  TooN_INCLUDE_DIR
  NAMES TooN/TooN.h
  PATH_SUFFIXES include
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

add_library(
  TooN::TooN
  ALIAS
  TooN
)
