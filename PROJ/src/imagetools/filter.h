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
#ifndef IMAGETOOLS_FILTER_H_
#define IMAGETOOLS_FILTER_H_

#include <string>
#include "imagetools/color_data.h"
#include "imagetools/float_matrix.h"
#include "imagetools/pixel_buffer.h"

namespace image_tools {

/**
    @brief The base class for an image filter tool.  Every filter "has a" matrix
    or buffer. Subclasses must define this buffer by setting every pixel in the
    CalculateFilteredPixel pure virtual method. This base class will then be
    able to apply the buffer to a pixel buffer (using template method
    ApplyToBuffer) as the filter is applied interactively.
*/
class Filter {
 public:
  Filter();
  virtual ~Filter();

  /**
  Every filter subclasses will have its own buffer/matrix and the buffer will be
  used in this template method that could help to set each pixel with specific
  color in each (x, y) coordinate.
  */
  void ApplyToBuffer(PixelBuffer* buffer);

  /**
  Memory allocate any pointer needed for kernel in convolution filter
  */
  virtual void SetupFilter();

  /**
  The pure virtual method that calculate every pixel for specific filter.
  */
  virtual ColorData CalculateFilteredPixel(PixelBuffer* buffer, int x, int y) =
                                                                              0;

  /**
  Delete any pointer from convolution filter
  */
  virtual void CleanupFilter();

  /**
  A flag that determine if the buffer is used for basic filter or convolution
  filter
  */
  virtual bool can_calculate_in_place();

 private:
  Filter(const Filter &rhs) = delete;
  Filter &operator=(const Filter &rhs) = delete;
};

}  // namespace image_tools

#endif  // IMAGETOOLS_FILTER_H_
