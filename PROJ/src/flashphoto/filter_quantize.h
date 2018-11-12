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
#ifndef FLASHPHOTO_FILTER_QUANTIZE_H_
#define FLASHPHOTO_FILTER_QUANTIZE_H_

#include <string>
#include "flashphoto/filter.h"

namespace image_tools {

class FilterQuantize : public Filter {
 public:
  explicit FilterQuantize(int numBin);

  virtual ~FilterQuantize();

  static const std::string name() { return "Quantize"; }

  ColorData CalculateFilteredPixel(PixelBuffer* buffer, int x, int y) override;

  int numBin() {
    return numBin_;
  }

 private:
  int numBin_;
};

}  // namespace image_tools

#endif  // FLASHPHOTO_FILTER_QUANTIZE_H_
