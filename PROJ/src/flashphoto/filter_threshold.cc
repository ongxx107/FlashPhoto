
#include <cmath>
#include "flashphoto/filter_threshold.h"
#include "flashphoto/color_data.h"
#include "flashphoto/pixel_buffer.h"

namespace image_tools {

FilterThreshold::FilterThreshold(float value) {
  value_ = value;
}

FilterThreshold::~FilterThreshold() {
}

ColorData FilterThreshold::CalculateFilteredPixel(PixelBuffer* buffer, int x,
  int y) {
  ColorData color = buffer->pixel(x, y);
  float red = color.red();
  float green = color.green();
  float blue = color.blue();

  float average = (red + green + blue)/3;

  if (average > value()){
    return ColorData(1.0, 1.0, 1.0);
  }
  else{
    return ColorData(0.0, 0.0, 0.0);
  }

}

} /* namespace image_tools */
