#ifndef FLASHPHOTO_FILTER_SHARPEN_H_
#define FLASHPHOTO_FILTER_SHARPEN_H_

#include <string>
#include "flashphoto/float_matrix.h"
#include "flashphoto/convolution_filter.h"

namespace image_tools {

class ConvolutionFilterSharpen : public ConvolutionFilter {
 public:
  ConvolutionFilterSharpen(float radius);

  virtual ~ConvolutionFilterSharpen();

  static const std::string name() { return "Convolution Filter Sharpenn"; }

  FloatMatrix* CreateKernel() override;

  int radius(){
    return radius_;
  }

 private:
   float radius_;
};

}  // namespace image_tools

#endif  // FLASHPHOTO_FILTER_SHARPEN_H_
