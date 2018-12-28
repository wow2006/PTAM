# ===========================================
# find GVars library and header
find_path(
  GVars3_INCLUDE_DIR
  NAMES gvars3/gvars3.h
  PATH_SUFFIXES include
)

find_library(
  GVars3_LIBRARY
  NAMES GVars3
  PATH_SUFFIXES lib
)

find_library(
  GVars3_headless_LIBRARY
  GVars3_headless
  PATH_SUFFIXES lib
)
# ===========================================

# ===========================================
# find pthreads
find_package(Threads REQUIRED)
# ===========================================

add_library(
  GVars3
  INTERFACE
)

target_link_libraries(
  CVD
  INTERFACE
  ${GVars3_LIBRARY}
  Threads::Threads
)

target_include_directories(
  GVars3
  SYSTEM INTERFACE
  ${GVars3_INCLUDE_DIR}
)

add_library(
  GVars3_headless
  INTERFACE
)

target_link_libraries(
  GVars3_headless
  INTERFACE
  ${GVars3_headless_LIBRARY}
)

target_include_directories(
  GVars3_headless
  SYSTEM INTERFACE
  ${GVars3_INCLUDE_DIR}
)

add_library(
  GVars3::GVars
  ALIAS
  GVars3
)

add_library(
  GVars3::headless
  ALIAS
  GVars3_headless
)

