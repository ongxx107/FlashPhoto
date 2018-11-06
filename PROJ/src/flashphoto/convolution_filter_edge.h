#ifndef FLASHPHOTO_FILTER_EDGE_H_
#define FLASHPHOTO_FILTER_EDGE_H_

#include <string>
#include "flashphoto/float_matrix.h"
#include "flashphoto/convolution_filter.h"

namespace image_tools {

class ConvolutionFilterEdge : public ConvolutionFilter {
 public:
  ConvolutionFilterEdge();

  virtual ~ConvolutionFilterEdge();

  static const std::string name() { return "Convolution Filter Edge"; }

  FloatMatrix* CreateKernel() override;

};

}  // namespace image_tools

#endif  // FLASHPHOTO_FILTER_EDGE_H_
