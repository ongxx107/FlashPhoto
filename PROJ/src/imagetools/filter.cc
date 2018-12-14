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
#include <assert.h>
#include <algorithm>
#include <cmath>
#include "imagetools/filter.h"

namespace image_tools {

  Filter::Filter() {}

  Filter::~Filter() {}

  void Filter::SetupFilter() {}

  void Filter::CleanupFilter() {}

  void Filter::ApplyToBuffer(PixelBuffer *buffer) {
    if (!can_calculate_in_place()) {
      /*
      For convolution filter buffer iteration, it makes a fresh copy of buffer
      and uses it to calculate each pixel for specific filters. Once we
      calculated the pixel, we set the pixel in the original buffer.
      */
      PixelBuffer *dest = new PixelBuffer(*buffer);
      SetupFilter();
      for (int i = 0; i < buffer->height(); i++) {
        for (int j = 0; j < buffer->width(); j++) {
          ColorData color = CalculateFilteredPixel(dest, j, i);
          buffer->set_pixel(j, i, color);
        }
      }
      delete dest;
      CleanupFilter();
    } else {
      /*
      For basic filter buffer iteration, it calculates each pixel for specific
      filters. Once we calculated the pixel, we set the pixel in the original
      buffer.
      */
      SetupFilter();
      for (int i = 0; i < buffer->height(); i++) {
        for (int j = 0; j < buffer->width(); j++) {
          ColorData color = CalculateFilteredPixel(buffer, j, i);
          buffer->set_pixel(j, i, color);
        }
      }
      CleanupFilter();
    }
  }

  bool Filter::can_calculate_in_place() {
    return true;
  }
}  //  namespace image_tools
