
#include <cmath>
#include "flashphoto/filter_saturate.h"
#include "flashphoto/color_data.h"
#include "flashphoto/pixel_buffer.h"
#include "flashphoto/image_tools_math.h"

namespace image_tools {

FilterSaturate::FilterSaturate(float value) {
  value_ = value;
}

FilterSaturate::~FilterSaturate() {
}

ColorData FilterSaturate::CalculateFilteredPixel(PixelBuffer* buffer, int x,
  int y) {
  ColorData color = buffer->pixel(x, y);

  float grayscaleValue = color.Luminance();
  ColorData grayscaleColor = ColorData(grayscaleValue, grayscaleValue,
    grayscaleValue); // grayscale version of color

  return (ColorData)ImageToolsMath::Lerp(grayscaleColor, color, value());
}

} /* namespace image_tools */
