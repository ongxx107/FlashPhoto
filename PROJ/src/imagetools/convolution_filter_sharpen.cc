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
#include <iostream>
#include "imagetools/convolution_filter_sharpen.h"
#include "imagetools/image_tools_math.h"

namespace image_tools {

ConvolutionFilterSharpen::ConvolutionFilterSharpen(float radius) {
  radius_ = radius;
}

ConvolutionFilterSharpen::~ConvolutionFilterSharpen() {
}

FloatMatrix* ConvolutionFilterSharpen::CreateKernel() {
  FloatMatrix* matt = new FloatMatrix(radius());
  for (int i = 0; i < matt->height(); i++) {
    for (int j = 0; j < matt->width(); j++) {
      /*
      In this iteration, kernel value is setup by computing standard
      deviation of (distance between currrent kernel value and center value)
      and the radius.
      */
      float dist = sqrt((radius()-i)*(radius()-i) +
                    (radius()-j)*(radius()-j));
      float result = ImageToolsMath::Gaussian(dist, radius());
      matt->set_value(j, i, result);
    }
  }
  matt->Normalize();
  matt->Scale(-1.0);
  matt->set_value(radius(), radius(), matt->value(radius(), radius()) + 2.0);

  return matt;
}

} /* namespace image_tools */
