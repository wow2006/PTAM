// -*- c++ -*-
// Copyright 2008 Isis Innovation Limited

#pragma once

#include <TooN/TooN.h>

#include <cvd/byte.h>
#include <cvd/image.h>

using namespace TooN;

namespace PTAM {

class CalibCornerPatch {
public:
  struct Params {
    Params();
    Matrix<2> m2Warp();
    Vector<2> v2Pos;
    Vector<2> v2Angles;
    double dMean;
    double dGain;
  };

  CalibCornerPatch(int nSideSize = 8);
  bool IterateOnImage(Params &params, CVD::Image<CVD::byte> &im);
  bool IterateOnImageWithDrawing(Params &params, CVD::Image<CVD::byte> &im);

protected:
  void MakeTemplateWithCurrentParams();
  void FillTemplate(CVD::Image<float> &im, Params params);
  double Iterate(CVD::Image<CVD::byte> &im);
  Params mParams;
  CVD::Image<float> mimTemplate;
  CVD::Image<Vector<2>> mimGradients;
  CVD::Image<Vector<2>> mimAngleJacs;

  void MakeSharedTemplate();
  static CVD::Image<float> mimSharedSourceTemplate;

  double mdLastError;
};

} // namespace PTAM
