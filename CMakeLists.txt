cmake_minimum_required(VERSION 3.9)
project(PTAM CXX)

add_executable(
  PTAM_DEMO
  main.cpp
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

