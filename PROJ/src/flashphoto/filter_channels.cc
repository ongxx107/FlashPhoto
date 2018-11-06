
#include <cmath>
#include "flashphoto/filter_channels.h"
#include "flashphoto/color_data.h"
#include "flashphoto/pixel_buffer.h"

namespace image_tools {

FilterChannels::FilterChannels(float r, float g, float b) {
  red_ = r;
  green_ = g;
  blue_ = b;
}

FilterChannels::~FilterChannels() {
}

ColorData FilterChannels::CalculateFilteredPixel(PixelBuffer* buffer, int x,
  int y) {
  ColorData color = buffer->pixel(x, y);
  float red = color.red();
  float green = color.green();
  float blue = color.blue();

  return ColorData(red*red_, green*green_, blue*blue_);
}

} /* namespace image_tools */
