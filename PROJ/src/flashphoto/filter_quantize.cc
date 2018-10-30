
#include <cmath>
#include "flashphoto/filter_quantize.h"
#include "flashphoto/color_data.h"
#include "flashphoto/pixel_buffer.h"

namespace image_filters {

FilterQuantize::FilterQuantize(int numBin) {
  numBin_ = numBin;
}

FilterQuantize::~FilterQuantize() {
}

ColorData FilterQuantize::CalculateFilteredPixel(PixelBuffer buffer, int x,
  int y) {
  ColorData color = buffer->pixel(x, y);
  float red = color->red();
  float green = color->green();
  float blue = color->blue();
  int numSteps = numBin_-1;

  red = round(red*numSteps)/numSteps;
  green = round(green*numSteps)/numSteps;
  blue = round(blue*numSteps)/numSteps;

  return ColorData::ColorData(red, green, blue);
}

} /* namespace image_filters */
