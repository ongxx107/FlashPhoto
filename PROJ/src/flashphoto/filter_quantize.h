#ifndef FLASHPHOTO_FILTER_QUANTIZE_H_
#define FLASHPHOTO_FILTER_QUANTIZE_H_

#include <string>
#include "flashphoto/filter.h"

namespace image_tools {

class FilterQuantize : public Filter {
 public:
  FilterQuantize(int numBin);

  virtual ~FilterQuantize();

  static const std::string name() { return "Quantize"; }

  ColorData CalculateFilteredPixel(PixelBuffer* buffer, int x, int y) override;

  int numBin(){
    return numBin_;
  }

 private:
   int numBin_;
};

}  // namespace image_tools

#endif  // FLASHPHOTO_FILTER_QUANTIZE_H_
