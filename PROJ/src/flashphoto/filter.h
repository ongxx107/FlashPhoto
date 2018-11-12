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
#ifndef FLASHPHOTO_FILTER_H_
#define FLASHPHOTO_FILTER_H_

#include <string>
#include "flashphoto/color_data.h"
#include "flashphoto/float_matrix.h"
#include "flashphoto/pixel_buffer.h"

namespace image_tools {

class Filter {
 public:
  Filter();
  virtual ~Filter();

  void ApplyToBuffer(PixelBuffer* buffer);

  virtual void SetupFilter();
  virtual ColorData CalculateFilteredPixel(PixelBuffer* buffer, int x, int y) =
                                                                              0;
  virtual void CleanupFilter();

  virtual bool can_calculate_in_place();

 private:
  Filter(const Filter &rhs) = delete;
  Filter &operator=(const Filter &rhs) = delete;
};

}  // namespace image_tools

#endif  // FLASHPHOTO_FILTER_H_
