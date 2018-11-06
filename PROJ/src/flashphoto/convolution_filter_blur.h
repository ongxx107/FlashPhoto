#ifndef FLASHPHOTO_FILTER_BLUR_H_
#define FLASHPHOTO_FILTER_BLUR_H_

#include <string>
#include "flashphoto/float_matrix.h"
#include "flashphoto/convolution_filter.h"

namespace image_tools {

class ConvolutionFilterBlur : public ConvolutionFilter {
 public:
  ConvolutionFilterBlur(float radius);

  virtual ~ConvolutionFilterBlur();

  static const std::string name() { return "Convolution Filter Blur"; }

  FloatMatrix* CreateKernel() override;

  int radius(){
    return radius_;
  }

 private:
   float radius_;
};

}  // namespace image_tools

#endif  // FLASHPHOTO_FILTER_BLUR_H_
