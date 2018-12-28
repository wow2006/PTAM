cmake_minimum_required(VERSION 3.9)
project(PTAM CXX)

list(
  APPEND
  CMAKE_MODULE_PATH
  ${CMAKE_SOURCE_DIR}/cmake/modules
)

find_package(CVD REQUIRED)
find_package(TooN REQUIRED)
find_package(GVars3 REQUIRED)

add_executable(
  PTAM_DEMO
  main.cpp
)

target_include_directories(
  PTAM_DEMO
  PUBLIC
  ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(
  PTAM_DEMO
  PUBLIC
  CVD::CVD
  TooN::TooN
  GVars3::GVars
)

target_compile_features(
  PTAM_DEMO
  PUBLIC
  cxx_std_17
)

target_compile_options(
  PTAM_DEMO
  PUBLIC
  $<$<CXX_COMPILER_ID:Clang>:-Weverything -fcolor-diagnostics -Wno-c++98-compat>
)

