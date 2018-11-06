#include <assert.h>
#include <algorithm>
#include <cmath>
#include "flashphoto/convolution_filter.h"
#include "flashphoto/image_tools_math.h"

namespace image_tools {

  ConvolutionFilter::ConvolutionFilter() {}

  ConvolutionFilter::~ConvolutionFilter() {}

  void ConvolutionFilter::SetupFilter() {
      mat = CreateKernel();
  }

  void ConvolutionFilter::CleanupFilter() {
      delete mat;
  }

  ColorData ConvolutionFilter::CalculateFilteredPixel(PixelBuffer* buffer,
    int x, int y) {

    int mat_height_half = (mat->height())/2;
    int mat_width_half = (mat->width())/2;

    double red = 0.0;
    double green = 0.0;
    double blue = 0.0;

    for (int filterY = 0; filterY < mat->height(); filterY++){
      for (int filterX = 0; filterX < mat->width(); filterX++){

        int imageX = (x - mat_width_half + filterX + buffer->width()) % buffer->width();
        int imageY = (y - mat_height_half + filterY + buffer->height()) % buffer->height();

        red += buffer->pixel(imageX, imageY).red() * mat->value(filterX, filterY);
        green += buffer->pixel(imageX, imageY).green() * mat->value(filterX, filterY);
        blue += buffer->pixel(imageX, imageY).blue() * mat->value(filterX, filterY);

      }
    }

    red = ImageToolsMath::Clamp(0.0, red, 1.0);
    green = ImageToolsMath::Clamp(0.0, green, 1.0);
    blue = ImageToolsMath::Clamp(0.0, blue, 1.0);
    return ColorData(red, green, blue);

    }


  bool ConvolutionFilter::can_calculate_in_place(){
    return false;
  }



}
