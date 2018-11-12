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
#ifndef FLASHPHOTO_CONVOLUTION_FILTER_H_
#define FLASHPHOTO_CONVOLUTION_FILTER_H_

#include <string>
#include "flashphoto/color_data.h"
#include "flashphoto/float_matrix.h"
#include "flashphoto/pixel_buffer.h"
#include "flashphoto/filter.h"

namespace image_tools {

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

#endif  // FLASHPHOTO_CONVOLUTION_FILTER_H_
