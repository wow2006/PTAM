// -*- c++ -*-
// Copyright 2008 Isis Innovation Limited
//
// MapViewer.h
//
// Defines the MapViewer class
//
// This defines a simple map viewer widget, which can draw the
// current map and the camera/keyframe poses within it.
//
#pragma once

#include <sstream>

#include <TooN/TooN.h>
#include <TooN/se3.h>

#include "PTAM/GLWindow2.hpp"

#include "Map.h"

using namespace TooN;

namespace PTAM {
class Map;

class MapViewer {
public:
  /** 
  * @brief 
  * 
  * @param map
  * @param glw
  */
  MapViewer(Map &map, GLWindow2 &glw);

  /** 
  * @brief 
  * 
  * @param se3CamFromWorld
  */
  void DrawMap(SE3<> se3CamFromWorld);

  /** 
  * @brief 
  * 
  * @return 
  */
  std::string GetMessageForUser();

protected:
  Map &mMap;

  GLWindow2 &mGLWindow;

  /** 
  * @brief 
  */
  void DrawGrid();

  /** 
  * @brief 
  */
  void DrawMapDots();

  /** 
  * @brief 
  * 
  * @param se3
  * @param bSmall
  */
  void DrawCamera(SE3<> se3, bool bSmall = false);

  /** 
  * @brief 
  */
  void SetupFrustum();

  /** 
  * @brief 
  * 
  * @param se3WorldFromCurrent
  */
  void SetupModelView(SE3<> se3WorldFromCurrent = SE3<>());

  Vector<3> mv3MassCenter;
  SE3<> mse3ViewerFromWorld;

  std::ostringstream mMessageForUser;
};
} // namespace PTAM
