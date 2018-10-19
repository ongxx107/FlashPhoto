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
  ...
*/

#include "flashphoto/tool_blur.h"
#include "flashphoto/mask_factory.h"

namespace image_tools {

ToolBlur::ToolBlur() {
}

ToolBlur::~ToolBlur() {
}

FloatMatrix* ToolBlur::CreateMask(float radius) {
  return MaskFactory::CreateConstantMask(radius);
}

} /* namespace image_tools */

