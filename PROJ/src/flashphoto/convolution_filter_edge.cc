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
#include <cmath>
#include "flashphoto/convolution_filter_edge.h"
#include "flashphoto/image_tools_math.h"

namespace image_tools {

ConvolutionFilterEdge::ConvolutionFilterEdge() {
}

ConvolutionFilterEdge::~ConvolutionFilterEdge() {
}

FloatMatrix* ConvolutionFilterEdge::CreateKernel() {
  /*
  Since we were informed that the kernel for filter edge is 3 by 3 matrix,
  we set all 9 entries with -1 first, and set the center point to 8.
  */
  FloatMatrix* matt = new FloatMatrix(3, 3);

  for (int i = 0; i < matt->height(); i++) {
    for (int j = 0; j < matt->width(); j++) {
      matt->set_value(i, j, -1);
    }
  }
  float r = round(matt->width()/2);
  int finalRadius = r;
  matt->set_value(finalRadius, finalRadius, 8);

  return matt;
}

} /* namespace image_tools */
