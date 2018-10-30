
#include <cmath>
#include "flashphoto/filter_saturate.h"
#include "flashphoto/color_data.h"
#include "flashphoto/pixel_buffer.h"

namespace image_filters {

FilterSaturate::FilterSaturate(float value) {
  value_ = value;
}

FilterSaturate::~FilterSaturate() {
}

ColorData FilterSaturate::CalculateFilteredPixel(PixelBuffer buffer, int x,
  int y) {
  ColorData color = buffer->pixel(x, y);
  float grayscaleValue = color->Luminance();
  ColorData grayscaleColor = ColorData(grayscaleValue, grayscaleValue,
    grayscaleValue); // grayscale version of color
  ColorData result = Lerp(grayscaleColor, color, value_);

  return result;
}

} /* namespace image_filters */
