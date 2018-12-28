// -*- c++ -*-
// Copyright 2008 Isis Innovation Limited
// ARDriver.h
// This file declares the ARDriver class
//
// ARDriver provides basic graphics services for drawing augmented
// graphics. It manages the OpenGL setup and the camera's radial
// distortion so that real and distorted virtual graphics can be
// properly blended.
//
#pragma once
#include <TooN/se3.h>

#include <cvd/byte.h>
#include <cvd/image.h>
#include <cvd/rgb.h>

#include "PTAM/ATANCamera.hpp"
#include "PTAM/GLWindow2.hpp"
#include "PTAM/OpenGL.hpp"

#include "EyeGame.h"

using namespace std;
using namespace CVD;

namespace PTAM {

class ARDriver {
public:
  /**
   * @brief
   *
   * @param cam
   * @param irFrameSize
   * @param glw
   */
  ARDriver(const ATANCamera &cam, ImageRef irFrameSize, GLWindow2 &glw);

  /**
   * @brief
   *
   * @param imFrame
   * @param se3CamFromWorld
   */
  void Render(Image<Rgb<byte>> &imFrame, SE3<> se3CamFromWorld);

  /**
   * @brief
   */
  void Reset();

  /**
   * @brief
   */
  void Init();

protected:
  ATANCamera mCamera;

  GLWindow2 &mGLWindow;

  /**
   * @brief
   */
  void DrawFadingGrid();

  /**
   * @brief
   */
  void MakeFrameBuffer();

  /**
   * @brief
   */
  void DrawFBBackGround();

  /**
   * @brief
   */
  void DrawDistortedFB();

  /**
   * @brief
   */
  void SetFrustum();

  // Texture stuff:
  GLuint mnFrameBuffer;
  GLuint mnFrameBufferTex;
  GLuint mnFrameTex;

  int mnCounter;
  ImageRef mirFBSize;
  ImageRef mirFrameSize;
  SE3<> mse3;
  bool mbInitialised;

  // Eyeballs:
  EyeGame mGame;
};

} // namespace PTAM
