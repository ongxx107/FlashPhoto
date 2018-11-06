#ifndef FLASHPHOTO_FILTER_MOTION_BLUR_H_
#define FLASHPHOTO_FILTER_MOTION_BLUR_H_

#include <string>
#include "flashphoto/float_matrix.h"
#include "flashphoto/convolution_filter.h"
// #include "flashphoto/flashphoto_app.h"

namespace image_tools {

class ConvolutionFilterMotionBlur : public ConvolutionFilter {
 public:
  ConvolutionFilterMotionBlur(float radius, std::string dir);

  virtual ~ConvolutionFilterMotionBlur();

  static const std::string name() { return "Convolution Filter Motion Blur"; }

  FloatMatrix* CreateKernel() override;

  int radius(){
    return radius_;
  }

  std::string dir(){
    return dir_;
  }

 private:
   float radius_;
   std::string dir_;
};

}  // namespace image_tools

#endif  // FLASHPHOTO_FILTER_MOTION_BLUR_H_
