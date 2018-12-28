find_path(
  CVD_INCLUDE_DIR
  NAMES cvd/config.h
  PATH_SUFFIXES include
)

find_library(
  CVD_LIBRARY
  NAMES CVD
  PATH_SUFFIXES lib
)

find_package(X11 REQUIRED)
set(OpenGL_GL_PREFERENCE LEGACY)
find_package(OpenGL REQUIRED)

add_library(
  CVD
  INTERFACE
)

target_link_libraries(
  CVD
  INTERFACE
  ${CVD_LIBRARY}
  ${X11_LIBRARIES}
  OpenGL::GL
)

target_include_directories(
  CVD
  SYSTEM INTERFACE
  ${CVD_INCLUDE_DIR}
)

add_library(
  CVD::CVD
  ALIAS
  CVD
)
