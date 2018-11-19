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
#include "imagetools/convolution_filter_motion_blur.h"
#include "imagetools/image_tools_math.h"

namespace image_tools {

ConvolutionFilterMotionBlur::ConvolutionFilterMotionBlur(float radius,
  std::string dir) {
  radius_ = radius;
  dir_ = dir;
}

ConvolutionFilterMotionBlur::~ConvolutionFilterMotionBlur() {
}

FloatMatrix* ConvolutionFilterMotionBlur::CreateKernel() {
  FloatMatrix* matt = new FloatMatrix(radius());
  float factor = 1.0/matt->height();

  for (int x = 0; x < matt->width(); x++) {
    for (int y = 0; y < matt->height(); y++) {
      matt->set_value(x, y, 0);
    }
  }

  if (dir() == "North/South") {
    for (int y = 0; y < matt->height(); y++) {
      matt->set_value(radius(), y, factor);
    }
  } else if (dir() == "East/West") {
    for (int x = 0; x < matt->width(); x++) {
      matt->set_value(x, radius(), factor);
    }
  } else if (dir() == "Northeast/Southwest") {
    int counter = 0;
    for (int x = matt->width()-1; x >= 0; x--) {
      matt->set_value(x, counter, factor);
      counter++;
    }
  } else {  //  "Northwest/Southeast"
    for (int x = 0; x < matt->width(); x++) {
      matt->set_value(x, x, factor);
    }
  }

  return matt;
}

} /* namespace image_tools */
