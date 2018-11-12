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
#ifndef FLASHPHOTO_CONVOLUTION_FILTER_EDGE_H_
#define FLASHPHOTO_CONVOLUTION_FILTER_EDGE_H_

#include <string>
#include "flashphoto/float_matrix.h"
#include "flashphoto/convolution_filter.h"

namespace image_tools {

class ConvolutionFilterEdge : public ConvolutionFilter {
 public:
  ConvolutionFilterEdge();

  virtual ~ConvolutionFilterEdge();

  static const std::string name() { return "Convolution Filter Edge"; }

  FloatMatrix* CreateKernel() override;
};

}  // namespace image_tools

#endif  // FLASHPHOTO_CONVOLUTION_FILTER_EDGE_H_