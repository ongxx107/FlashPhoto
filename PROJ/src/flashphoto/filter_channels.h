#ifndef FLASHPHOTO_FILTER_CHANNELS_H_
#define FLASHPHOTO_FILTER_CHANNELS_H_

#include <string>
#include "flashphoto/filter.h"

namespace image_tools {

class FilterChannels : public Filter {
 public:
  FilterChannels(float r, float g, float b);

  virtual ~FilterChannels();

  static const std::string name() { return "Channels"; }

  ColorData CalculateFilteredPixel(PixelBuffer* buffer, int x, int y) override;

  float red(){
    return red_;
  }

  float green(){
    return green_;
  }

  float blue(){
    return blue_;
  }

 private:
   float red_;
   float green_;
   float blue_;
};

}  // namespace image_tools

#endif  // FLASHPHOTO_FILTER_CHANNELS_H_
