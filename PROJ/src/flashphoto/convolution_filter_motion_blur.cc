
#include <cmath>
#include "flashphoto/convolution_filter_motion_blur.h"
#include "flashphoto/image_tools_math.h"

namespace image_tools {

ConvolutionFilterMotionBlur::ConvolutionFilterMotionBlur(float radius, std::string dir) {
  radius_ = radius;
  dir_ = dir;
}

ConvolutionFilterMotionBlur::~ConvolutionFilterMotionBlur() {
}

FloatMatrix* ConvolutionFilterMotionBlur::CreateKernel() {
  FloatMatrix* matt = new FloatMatrix(radius());
  float factor = 1.0/matt->height();

  for (int x = 0; x < matt->width(); x++){
    for (int y = 0; y < matt->height(); y++){
      matt->set_value(x, y, 0);
    }
  }

  if (dir() == "North/South"){
    for (int y = 0; y < matt->height(); y++){
      matt->set_value(radius(), y, factor);
    }
  }
  else if (dir() == "East/West"){
    for (int x = 0; x < matt->width(); x++){
      matt->set_value(x, radius(), factor);
    }
  }
  else if (dir() == "Northeast/Southwest"){
    int counter = 0;
    for (int x = matt->width()-1; x >= 0; x--){
      matt->set_value(x, counter, factor);
      counter++;
    }
  }
  else{ //"Northwest/Southeast"
    for (int x = 0; x < matt->width(); x++){
      matt->set_value(x, x, factor);
    }
  }

  return matt;
}

} /* namespace image_tools */
