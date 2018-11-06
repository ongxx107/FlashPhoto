#ifndef FLASHPHOTO_FILTER_SATURATE_H_
#define FLASHPHOTO_FILTER_SATURATE_H_

#include <string>
#include "flashphoto/filter.h"

namespace image_tools {

class FilterSaturate : public Filter {
 public:
  FilterSaturate(float value);

  virtual ~FilterSaturate();

  static const std::string name() { return "Saturate"; }

  ColorData CalculateFilteredPixel(PixelBuffer* buffer, int x, int y) override;

  float value(){
    return value_;
  }

 private:
   float value_;
};

}  // namespace image_tools

#endif  // FLASHPHOTO_FILTER_SATURATE_H_
