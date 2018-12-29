// -*- c++ -*-
// Copyright 2008 Isis Innovation Limited
//
// MiniPatch.h
//
// Declares MiniPatch class
//
// This is a simple pixel-patch class, used for tracking small patches
// it's used by the tracker for building the initial map
#pragma once

#include <vector>

#include <cvd/colourspace_convert.h>
#include <cvd/utility.h>
#include <cvd/byte.h>
#include <cvd/image.h>

#include <TooN/TooN.h>

using namespace TooN;

namespace PTAM {

struct MiniPatch {
  /**
   * @brief Copy pixels out of source image
   *
   * @param irPos
   * @param im
   */
  void SampleFromImage(CVD::ImageRef irPos, CVD::BasicImage<CVD::byte> &im);

  /**
   * @brief Find patch in a new image
   *
   * @param irPos
   * @param im
   * @param nRange
   * @param vCorners
   * @param pvRowLUT
   *
   * @return
   */
  bool FindPatch(CVD::ImageRef &irPos, CVD::BasicImage<CVD::byte> &im,
                 int nRange, std::vector<CVD::ImageRef> &vCorners,
                 std::vector<int> *pvRowLUT = NULL);

  /**
   * @brief Score function
   *
   * @param im
   * @param ir
   *
   * @return
   */
  int SSDAtPoint(CVD::BasicImage<CVD::byte> &im, const CVD::ImageRef &ir);

  static int mnHalfPatchSize;         // How big is the patch?
  static int mnRange;                 // How far to search?
  static int mnMaxSSD;                // Max SSD for matches?
  CVD::Image<CVD::byte> mimOrigPatch; // Original pixels
};

} // namespace PTAM
