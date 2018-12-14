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
#ifndef IMAGETOOLS_CONVOLUTION_FILTER_H_
#define IMAGETOOLS_CONVOLUTION_FILTER_H_

#include <string>
#include "imagetools/color_data.h"
#include "imagetools/float_matrix.h"
#include "imagetools/pixel_buffer.h"
#include "imagetools/filter.h"

namespace image_tools {

/**
@brief The parent class of convolution_filters and child class of filter. It
creates a kernel matrix pointer from SetupFilter() and eventually delete the
kernel after all of the pixel are calculated.
*/
class ConvolutionFilter : public Filter{
 public:
  ConvolutionFilter();
  virtual ~ConvolutionFilter();

  virtual FloatMatrix* CreateKernel() = 0;

  void SetupFilter() override;

  ColorData CalculateFilteredPixel(PixelBuffer* buffer, int x, int y) override;

  void CleanupFilter() override;

  bool can_calculate_in_place() override;

 protected:
  FloatMatrix* mat;

 private:
  ConvolutionFilter(const ConvolutionFilter &rhs) = delete;
  ConvolutionFilter &operator=(const ConvolutionFilter &rhs) = delete;
};

}  // namespace image_tools

#endif  // IMAGETOOLS_CONVOLUTION_FILTER_H_
