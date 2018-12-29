// -*- c++ -*-
// Copyright 2008 Isis Innovation Limited
//
// SmallBlurryImage-based relocaliser
//
// Each KF stores a small, blurred version of itself;
// Just compare a small, blurred version of the input frame to all the KFs,
// choose the closest match, and then estimate a camera rotation by direct image
// minimisation.
#pragma once

#include <TooN/se2.h>

#include "PTAM/ATANCamera.hpp"
#include "PTAM/SmallBlurryImage.hpp"

#include "PTAM/Map.hpp"

namespace PTAM {

class Relocaliser {
public:
  /** 
  * @brief 
  * 
  * @param map
  * @param camera
  */
  Relocaliser(Map &map, ATANCamera &camera);

  /** 
  * @brief 
  * 
  * @param k
  * 
  * @return 
  */
  bool AttemptRecovery(KeyFrame &k);

  /** 
  * @brief 
  * 
  * @return 
  */
  SE3<> BestPose();

protected:
  /** 
  * @brief 
  * 
  * @param kCurrentF
  */
  void ScoreKFs(KeyFrame &kCurrentF);

  Map &mMap;
  ATANCamera mCamera;
  int mnBest;
  double mdBestScore;
  SE2<> mse2;
  SE3<> mse3Best;
};

} // namespace PTAM
