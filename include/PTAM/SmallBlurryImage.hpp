// -*- c++ -*-
// Copyright 2008 Isis Innovation Limited
//
// SmallBlurryImage - A small and blurry representation of an image.
// used by the relocaliser.
#pragma once

#include <TooN/se2.h>
#include <TooN/se3.h>

#include <cvd/byte.h>
#include <cvd/image.h>

#include "PTAM/ATANCamera.hpp"
#include "PTAM/KeyFrame.hpp"

namespace PTAM {

class SmallBlurryImage {
public:
  /**
   * @brief
   */
  SmallBlurryImage();

  /**
   * @brief
   *
   * @param kf
   * @param dBlur
   */
  SmallBlurryImage(KeyFrame &kf, double dBlur = 2.5);

  /**
   * @brief
   *
   * @param kf
   * @param dBlur
   */
  void MakeFromKF(KeyFrame &kf, double dBlur = 2.5);

  /**
   * @brief
   */
  void MakeJacs();

  /**
   * @brief
   *
   * @param other
   *
   * @return
   */
  double ZMSSD(SmallBlurryImage &other);

  /**
   * @brief
   *
   * @param other
   * @param nIterations
   *
   * @return
   */
  std::pair<SE2<>, double> IteratePosRelToTarget(SmallBlurryImage &other,
                                                 int nIterations = 10);

  /**
   * @brief
   *
   * @param se2
   * @param camera
   *
   * @return
   */
  static SE3<> SE3fromSE2(SE2<> se2, ATANCamera camera);

protected:
  CVD::Image<CVD::byte> mimSmall;
  CVD::Image<float> mimTemplate;
  CVD::Image<Vector<2>> mimImageJacs;
  bool mbMadeJacs;
  static CVD::ImageRef mirSize;
};

} // namespace PTAM
