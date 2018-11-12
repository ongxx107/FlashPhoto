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
#include <cmath>
#include "flashphoto/filter_quantize.h"
#include "flashphoto/color_data.h"
#include "flashphoto/pixel_buffer.h"

namespace image_tools {

FilterQuantize::FilterQuantize(int numBin) {
  numBin_ = numBin;
}

FilterQuantize::~FilterQuantize() {
}

ColorData FilterQuantize::CalculateFilteredPixel(PixelBuffer* buffer, int x,
  int y) {
  ColorData color = buffer->pixel(x, y);
  float red = color.red();
  float green = color.green();
  float blue = color.blue();
  int numSteps = numBin()-1;

  red = round(red*numSteps)/numSteps;
  green = round(green*numSteps)/numSteps;
  blue = round(blue*numSteps)/numSteps;

  ColorData result = ColorData(red, green, blue);
  return result;
}

} /* namespace image_tools */
