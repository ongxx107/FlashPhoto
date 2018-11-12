/**
This file is part of the CSCI-3081W Project Support Code, which was developed
at the University of Minnesota.

This code is to be used for student coursework.  It is not an open source
project.
Copyright (c) 2015-2018 Daniel Keefe, TAs, & Regents of the University of
Minnesota.

Original Author(s) of this File:
  Seth Johnson, 4/4/2015, University of Minnesota

Author(s) of Significant Updates/Modifications to the File:
  Ren Jeik Ong
*/
#ifndef FLASHPHOTO_CONVOLUTION_FILTER_MOTION_BLUR_H_
#define FLASHPHOTO_CONVOLUTION_FILTER_MOTION_BLUR_H_

#include <string>
#include "flashphoto/float_matrix.h"
#include "flashphoto/convolution_filter.h"

namespace image_tools {

class ConvolutionFilterMotionBlur : public ConvolutionFilter {
 public:
  ConvolutionFilterMotionBlur(float radius, std::string dir);

  virtual ~ConvolutionFilterMotionBlur();

  static const std::string name() { return "Convolution Filter Motion Blur"; }

  FloatMatrix* CreateKernel() override;

  int radius() {
    return radius_;
  }

  std::string dir() {
    return dir_;
  }

 private:
  float radius_;
  std::string dir_;
};

}  // namespace image_tools

#endif  // FLASHPHOTO_CONVOLUTION_FILTER_MOTION_BLUR_H_
