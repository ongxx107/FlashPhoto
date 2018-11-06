
#ifndef FLASHPHOTO_FILTER_H_
#define FLASHPHOTO_FILTER_H_

#include <string>
#include "flashphoto/color_data.h"
#include "flashphoto/float_matrix.h"
#include "flashphoto/pixel_buffer.h"

namespace image_tools {

class Filter {
 public:
  Filter();
  virtual ~Filter();

  void ApplyToBuffer(PixelBuffer* buffer);

  virtual void SetupFilter();
  virtual ColorData CalculateFilteredPixel(PixelBuffer* buffer, int x, int y) = 0;
  virtual void CleanupFilter();

  virtual bool can_calculate_in_place();

protected:
  PixelBuffer* copyBuf_;

private:
 Filter(const Filter &rhs) = delete;
 Filter &operator=(const Filter &rhs) = delete;

};

}  // namespace image_tools

#endif  // FLASHPHOTO_FILTER_H_
