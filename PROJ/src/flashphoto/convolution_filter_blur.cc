
#include <cmath>
#include <iostream>
#include "flashphoto/convolution_filter_blur.h"
#include "flashphoto/image_tools_math.h"

namespace image_tools {

ConvolutionFilterBlur::ConvolutionFilterBlur(float radius) {
  radius_ = radius;
}

ConvolutionFilterBlur::~ConvolutionFilterBlur() {
}

FloatMatrix* ConvolutionFilterBlur::CreateKernel() {
  FloatMatrix* matt = new FloatMatrix(radius());
  for(int i = 0; i < matt->height(); i++){
    for(int j = 0; j < matt->width(); j++){
      float dist = sqrt((radius()-i)*(radius()-i) +
                    (radius()-j)*(radius()-j));
      float result = ImageToolsMath::Gaussian(dist, radius());
      matt->set_value(j, i, result);
    }
  }
  matt->Normalize();
  return matt;
}

} /* namespace image_tools */
