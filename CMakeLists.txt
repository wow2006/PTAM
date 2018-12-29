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
  src/System.cpp
  src/GLWindow2.cpp
  src/GLWindowMenu.cpp
  src/ATANCamera.cpp
  src/ARDriver.cpp
  src/EyeGame.cpp
  src/MapViewer.cpp
  src/Map.cpp
  src/MapPoint.cpp
  src/KeyFrame.cpp
  src/ShiTomasi.cpp
  src/SmallBlurryImage.cpp
  src/MiniPatch.cpp
  src/Relocaliser.cpp
  src/PatchFinder.cpp
  src/Tracker.cpp
  src/MapMaker.cpp
  src/HomographyInit.cpp
  src/Bundle.cpp
  src/CalibCornerPatch.cpp
  #src/CameraCalibrator.cpp
  src/CalibImage.cpp
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

target_compile_definitions(
  PTAM_DEMO
  PUBLIC
  CVD_HAVE_TOON=1
)

