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
#ifndef IMAGETOOLS_FILTER_CHANNELS_H_
#define IMAGETOOLS_FILTER_CHANNELS_H_

#include <string>
#include "imagetools/filter.h"

namespace image_tools {

/**
@brief This basic filter takes some input scale factors (one float each for
red, green, and blue), simply multiply the R, G, and B component for each pixel
in the image by the scale factor.
*/
class FilterChannels : public Filter {
 public:
  FilterChannels(float r, float g, float b);

  virtual ~FilterChannels();

  static const std::string name() { return "Channels"; }

  ColorData CalculateFilteredPixel(PixelBuffer* buffer, int x, int y) override;

  float red() {
    return red_;
  }

  float green() {
    return green_;
  }

  float blue() {
    return blue_;
  }

 private:
  float red_;
  float green_;
  float blue_;
};

}  // namespace image_tools

#endif  // IMAGETOOLS_FILTER_CHANNELS_H_
