// Copyright 2008 Isis Innovation Limited
#pragma once

#include <cvd/byte.h>
#include <cvd/image.h>

namespace PTAM {
double FindShiTomasiScoreAtPoint(CVD::BasicImage<CVD::byte> &image,
                                 int nHalfBoxSize, CVD::ImageRef irCenter);
} // namespace PTAM
