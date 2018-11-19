/**
This file is part of the CSCI-3081W Project Support Code, which was developed
at the University of Minnesota.

This code is to be used for student coursework.  It is not an open source
project.
Copyright (c) 2015-2018 Daniel Keefe, TAs, & Regents of the University of
Minnesota.

Original Author(s) of this File:
  Seth Johnson, 2/15/15, University of Minnesota

Author(s) of Significant Updates/Modifications to the File:
  Ren Jeik Ong
*/
#include "imagetools/filter_threshold.h"
#include "imagetools/color_data.h"
#include "imagetools/pixel_buffer.h"

namespace image_tools {

FilterThreshold::FilterThreshold(float value) {
  value_ = value;
}

FilterThreshold::~FilterThreshold() {
}

ColorData FilterThreshold::CalculateFilteredPixel(PixelBuffer* buffer, int x,
  int y) {
  ColorData color = buffer->pixel(x, y);
  float red = color.red();
  float green = color.green();
  float blue = color.blue();

  float average = (red + green + blue)/3;

  if (average > value()) {
    return ColorData(1.0, 1.0, 1.0);
  } else {
    return ColorData(0.0, 0.0, 0.0);
  }
}

} /* namespace image_tools */
