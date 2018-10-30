
#include <cmath>
#include "flashphoto/filter_threshold.h"
#include "flashphoto/color_data.h"
#include "flashphoto/pixel_buffer.h"

namespace image_filters {

FilterThreshold::FilterThreshold(float value) {
  value_ = value;
}

FilterThreshold::~FilterThreshold() {
}

ColorData FilterThreshold::CalculateFilteredPixel(PixelBuffer buffer, int x,
  int y) {
  ColorData color = buffer->pixel(x, y);
  float red = color->red();
  float green = color->green();
  float blue = color->blue();

  if (red > value_){
    red = 1.0;
  }
  else{
    red = 0.0;
  }
  if (green > value_){
    green = 1.0;
  }
  else{
    green = 0.0;
  }
  if (blue > value_){
    blue = 1.0;
  }
  else{
    blue = 0.0;
  }

  return ColorData::ColorData(red, green, blue);
}

} /* namespace image_filters */
