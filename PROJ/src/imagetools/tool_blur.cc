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
#include "imagetools/tool_blur.h"
#include "imagetools/mask_factory.h"
#include "imagetools/image_tools_math.h"

namespace image_tools {

ToolBlur::ToolBlur() {
  blur_ = new ConvolutionFilterBlur(5.0);
  blur_->SetupFilter();

  // TODO(Students) setup your blur filter to use a radius of 5.0 here

  // the blur operation is not fast, so space the repeated applications of the
  // stamp out as far as we can get away with while still having it look good
  // 1/3 overlap is pretty good for this.
  stamp_overlap_ = 0.333;
}

ToolBlur::~ToolBlur() {
  blur_->CleanupFilter();
}

FloatMatrix* ToolBlur::CreateMask(float radius) {
  return MaskFactory::CreateLinearFalloffMask(radius);
}

ColorData ToolBlur::LookupPaintColor(int x, int y) {
  ColorData result = blur_->CalculateFilteredPixel(buffer_, x, y);
  return result;
}

} /* namespace image_tools */
