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
kernel after all of the pixel are calculated. CreateKernel() as factory method
is used for specific convolution filter.
*/
class ConvolutionFilter : public Filter{
 public:
  ConvolutionFilter();
  virtual ~ConvolutionFilter();

  /*
  This factory method makes a kernel matrix which is setup by specific
  convolution filter.
  */
  virtual FloatMatrix* CreateKernel() = 0;

  /*
  Mmeory allocate a local variable pointer for CreateKernel();
  */
  void SetupFilter() override;

  /*
  This pure virtual method iterates the kernel matrix and does the
  multiplication between kernel pixel value and neighboring pixel value.
  Eventually, the multiplication value is set into buffer .
  */
  ColorData CalculateFilteredPixel(PixelBuffer* buffer, int x, int y) override;

  /*
  Delete the allocated pointer from CreateKernel()
  */
  void CleanupFilter() override;

  /*
  Changes the boolean to flase that implies it's convolution filter
  */
  bool can_calculate_in_place() override;

 protected:
  FloatMatrix* mat;

 private:
  ConvolutionFilter(const ConvolutionFilter &rhs) = delete;
  ConvolutionFilter &operator=(const ConvolutionFilter &rhs) = delete;
};

}  // namespace image_tools

#endif  // IMAGETOOLS_CONVOLUTION_FILTER_H_
