#include "PTAM/VideoSource.hpp"

namespace PTAM {

VideoSource::VideoSource() {}

CVD::ImageRef VideoSource::Size() { return {}; };

void VideoSource::GetAndFillFrameBWandRGB(CVD::Image<CVD::byte> &imBW,
                                          CVD::Image<CVD::Rgb<CVD::byte>> &imRGB) {}

} // namespace PTAM
