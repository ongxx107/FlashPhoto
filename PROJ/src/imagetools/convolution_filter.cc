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
  Ren Jeik Ong 5343975
*/
#include <assert.h>
#include <algorithm>
#include "imagetools/convolution_filter.h"
#include "imagetools/image_tools_math.h"

namespace image_tools {

  ConvolutionFilter::ConvolutionFilter() {}

  ConvolutionFilter::~ConvolutionFilter() {}

  void ConvolutionFilter::SetupFilter() {
    /*
    setup the kernel matrix
    */
    mat_ = CreateKernel();
  }

  void ConvolutionFilter::CleanupFilter() {
    /*
    clean up the matrix pointer/ free the memory allocated in CPU
    */
    delete mat_;
  }

  ColorData ConvolutionFilter::CalculateFilteredPixel(PixelBuffer* buffer,
    int x, int y) {

    int mat_height_half = (mat_->height())/2;
    int mat_width_half = (mat_->width())/2;

    double red = 0.0;
    double green = 0.0;
    double blue = 0.0;

    for (int filterY = 0; filterY < mat_->height(); filterY++) {
      for (int filterX = 0; filterX < mat_->width(); filterX++) {
        /*
        The location imageX and imageY is calculated so that for the center
        element of the filter it'll be x, y, but for the other elements it'll be
        a pixel from the image to the left, right, top or bottom of x, y. Its
        modulo divided through the width (w) or height (h) of the image so that
        pixels outside the image will be wrapped around.
        sourced from https://lodev.org/cgtutor/filtering.html
        */
        int imageX = (x - mat_width_half + filterX + buffer->width())
                      % buffer->width();
        int imageY = (y - mat_height_half + filterY + buffer->height())
                      % buffer->height();

        /*
        add on the value of multiplication of buffer value and kernel value
        */
        double matValue = mat_->value(filterX, filterY);
        red += buffer->pixel(imageX, imageY).red() * matValue;
        green += buffer->pixel(imageX, imageY).green() * matValue;
        blue += buffer->pixel(imageX, imageY).blue() * matValue;
      }
    }

    ColorData result = ColorData(red, green, blue);
    result.Clamp();
    return result;
  }

  bool ConvolutionFilter::can_calculate_in_place() {
    return false;
  }
}  //  namespace image_tools
