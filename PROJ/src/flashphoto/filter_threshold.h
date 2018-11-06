
#ifndef FLASHPHOTO_FILTER_THRESHOLD_H_
#define FLASHPHOTO_FILTER_THRESHOLD_H_

#include <string>
#include "flashphoto/filter.h"

namespace image_tools {

class FilterThreshold : public Filter {
 public:
  FilterThreshold(float value);

  virtual ~FilterThreshold();

  static const std::string name() { return "Threshold"; }

  ColorData CalculateFilteredPixel(PixelBuffer* buffer, int x, int y) override;

  float value(){
    return value_;
  }

 private:
   float value_;
};

}  // namespace image_tools

#endif  // FLASHPHOTO_FILTER_THRESHOLD_H_
