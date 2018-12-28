// -*- c++ -*-
// Copyright 2008 Isis Innovation Limited
//
// EyeGame.h
// Declares the EyeGame class
// EyeGame is a trivial AR app which draws some 3D graphics
// Draws a bunch of 3d eyeballs remniscient of the
// AVL logo
//
#pragma once
#include <TooN/TooN.h>
using namespace TooN;
#include "PTAM/OpenGL.hpp"

namespace PTAM {

class EyeGame {
public:
  /** 
  * @brief 
  */
  EyeGame();

  /** 
  * @brief 
  * 
  * @param v3CameraPos
  */
  void DrawStuff(Vector<3> v3CameraPos);

  /** 
  * @brief 
  */
  void Reset();

  /** 
  * @brief 
  */
  void Init();

protected:
  bool mbInitialised;

  /** 
  * @brief 
  */
  void DrawEye();

  /** 
  * @brief 
  * 
  * @param nEye
  * @param v3
  * @param dRotLimit
  */
  void LookAt(int nEye, Vector<3> v3, double dRotLimit);

  /** 
  * @brief 
  */
  void MakeShadowTex();

  GLuint mnEyeDisplayList;
  GLuint mnShadowTex;
  double mdEyeRadius;
  double mdShadowHalfSize;
  SE3<> ase3WorldFromEye[4];
  int mnFrameCounter;
};
} // namespace PTAM

