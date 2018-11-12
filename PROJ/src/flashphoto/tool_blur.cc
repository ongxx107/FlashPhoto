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
#include "flashphoto/tool_blur.h"
#include "flashphoto/mask_factory.h"
#include "flashphoto/image_tools_math.h"

namespace image_tools {

ToolBlur::ToolBlur() {
  /*
  blur_ = new FloatMatrix(radius());
  for(int i = 0; i < blur_->height(); i++){
    for(int j = 0; j < blur_->width(); j++){
      float dist = sqrt((radius()-i)*(radius()-i) +
                    (radius()-j)*(radius()-j));
      float result = ImageToolsMath::Gaussian(dist, radius());
      blur_->set_value(j, i, result);
    }
  }
  blur_->Normalize();
  */
  blur_ = new ConvolutionFilterBlur(5.0);
  blur_->SetupFilter();
  // the blur operation is not fast, so space the repeated applications of the
  // stamp out as far as we can get away with while still having it look good
  // 1/3 overlap is pretty good for this.
  stamp_overlap_ = 0.333;
}

ToolBlur::~ToolBlur() {
  // TODO(ongxx107): Students cleanup your filter here if needed.
  blur_->CleanupFilter();
}

FloatMatrix* ToolBlur::CreateMask(float radius) {
  return MaskFactory::CreateLinearFalloffMask(radius);
}

ColorData ToolBlur::LookupPaintColor(int x, int y) {
  // TODO(ongxx107): Students, here's your hook to calculate a filtered version
  // of the pixel. Use your filter to compute the blurred version of the pixel
  // at (x,y) in *buffer_ and return the new color to make this tool work.

  // Remove this:  As a placeholder, we're just returning the original pixel
  // color for now.
  /*
  int mat_height_half = (blur_->height())/2;
  int mat_width_half = (blur_->width())/2;

  double red = 0.0;
  double green = 0.0;
  double blue = 0.0;

  for (int filterY = 0; filterY < blur_->height(); filterY++){
    for (int filterX = 0; filterX < blur_->width(); filterX++){

      int imageX = (x - mat_width_half + filterX + buffer_->width()) % buffer_->width();
      int imageY = (y - mat_height_half + filterY + buffer_->height()) % buffer_->height();

      red += buffer_->pixel(imageX, imageY).red() * blur_->value(filterX, filterY);
      green += buffer_->pixel(imageX, imageY).green() * blur_->value(filterX, filterY);
      blue += buffer_->pixel(imageX, imageY).blue() * blur_->value(filterX, filterY);

    }
  }

  red = ImageToolsMath::Clamp(0.0, red, 1.0);
  green = ImageToolsMath::Clamp(0.0, green, 1.0);
  blue = ImageToolsMath::Clamp(0.0, blue, 1.0);
  return ColorData(red, green, blue);
  */

  ColorData result = blur_->CalculateFilteredPixel(buffer_, x, y);
  return result;
}

} /* namespace image_tools */
