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
#include "imagetools/filter_saturate.h"
#include "imagetools/color_data.h"
#include "imagetools/pixel_buffer.h"
#include "imagetools/image_tools_math.h"

namespace image_tools {

FilterSaturate::FilterSaturate(float value) {
  value_ = value;
}

FilterSaturate::~FilterSaturate() {
}

ColorData FilterSaturate::CalculateFilteredPixel(PixelBuffer* buffer, int x,
  int y) {
  ColorData color = buffer->pixel(x, y);

  float grayscaleValue = color.Luminance();
  ColorData grayscaleColor = ColorData(grayscaleValue, grayscaleValue,
    grayscaleValue);  //  grayscale version of color

  return (ColorData)ImageToolsMath::Lerp(grayscaleColor, color, value());
}

} /* namespace image_tools */
