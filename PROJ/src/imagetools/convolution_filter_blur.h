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
#ifndef IMAGETOOLS_CONVOLUTION_FILTER_BLUR_H_
#define IMAGETOOLS_CONVOLUTION_FILTER_BLUR_H_

#include <string>
#include "imagetools/float_matrix.h"
#include "imagetools/convolution_filter.h"

namespace image_tools {

/**
    This Filter BLur class takes radius as an argument and creates a
    kernel matrix based on radius. The height and width were setup with
    2 * (round off of radius) + 1. In the iteration of kernel matrix,
    it calculates the distance between each pixel and center point which is
    coordinated at (radius, radius). Then, the distance is used for Gaussian
    Blur formula.
*/
class ConvolutionFilterBlur : public ConvolutionFilter {
 public:
  explicit ConvolutionFilterBlur(float radius);

  virtual ~ConvolutionFilterBlur();

  static const std::string name() { return "Convolution Filter Blur"; }

  FloatMatrix* CreateKernel() override;

  int radius() {
    return radius_;
  }

 private:
  float radius_;
};

}  // namespace image_tools

#endif  // IMAGETOOLS_CONVOLUTION_FILTER_BLUR_H_
