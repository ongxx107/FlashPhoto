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
#ifndef FLASHPHOTO_FILTER_SATURATE_H_
#define FLASHPHOTO_FILTER_SATURATE_H_

#include <string>
#include "flashphoto/filter.h"

namespace image_tools {

class FilterSaturate : public Filter {
 public:
  explicit FilterSaturate(float value);

  virtual ~FilterSaturate();

  static const std::string name() { return "Saturate"; }

  ColorData CalculateFilteredPixel(PixelBuffer* buffer, int x, int y) override;

  float value() {
    return value_;
  }

 private:
  float value_;
};

}  // namespace image_tools

#endif  // FLASHPHOTO_FILTER_SATURATE_H_
