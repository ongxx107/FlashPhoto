
#include <cmath>
#include "flashphoto/convolution_filter_edge.h"
#include "flashphoto/image_tools_math.h"

namespace image_tools {

ConvolutionFilterEdge::ConvolutionFilterEdge() {
}

ConvolutionFilterEdge::~ConvolutionFilterEdge() {
}

FloatMatrix* ConvolutionFilterEdge::CreateKernel() {
  FloatMatrix* matt = new FloatMatrix(3, 3);

  for(int i = 0; i < matt->height(); i++){
    for(int j = 0; j < matt->width(); j++){
      matt->set_value(i, j, -1);
    }
  }
  float r = round(matt->width()/2);
  int finalRadius = (int)r;
  matt->set_value(finalRadius, finalRadius, 8);

  return matt;
}

} /* namespace image_tools */
