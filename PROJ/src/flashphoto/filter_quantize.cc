
#include <cmath>
#include "flashphoto/filter_quantize.h"
#include "flashphoto/color_data.h"
#include "flashphoto/pixel_buffer.h"

namespace image_tools {

FilterQuantize::FilterQuantize(int numBin) {
  numBin_ = numBin;
}

FilterQuantize::~FilterQuantize() {
}

ColorData FilterQuantize::CalculateFilteredPixel(PixelBuffer* buffer, int x,
  int y) {
  ColorData color = buffer->pixel(x, y);
  float red = color.red();
  float green = color.green();
  float blue = color.blue();
  //std::cout << numBin();
  int numSteps = numBin()-1;

  red = round(red*numSteps)/numSteps;
  green = round(green*numSteps)/numSteps;
  blue = round(blue*numSteps)/numSteps;

  ColorData result = ColorData(red, green, blue);

  //set
  return result;

}

} /* namespace image_tools */
