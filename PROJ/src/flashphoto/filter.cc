#include <assert.h>
#include <algorithm>
#include <cmath>
#include "flashphoto/filter.h"

namespace image_tools {

  Filter::Filter() {}

  Filter::~Filter() {}

  void Filter::SetupFilter() {}

  void Filter::CleanupFilter() {}

  void Filter::ApplyToBuffer(PixelBuffer *buffer) {

    if (!can_calculate_in_place()){
      printf("here1 \n");
      PixelBuffer *dest = new PixelBuffer(*buffer);
      SetupFilter();
      for(int i=0; i<buffer->height(); i++){
        for(int j=0; j<buffer->width(); j++){
          ColorData color = CalculateFilteredPixel(dest, j, i);
          buffer->set_pixel(j, i, color);

        }
      }
      printf("here2 \n");
      delete dest;
      CleanupFilter();
      printf("here3 \n");
    }
    else{
      SetupFilter();
      for(int i=0; i<buffer->height(); i++){
        for(int j=0; j<buffer->width(); j++){
          ColorData color = CalculateFilteredPixel(buffer, j, i);
          buffer->set_pixel(j, i, color);
        }
      }
      CleanupFilter();
    }

  }

  bool Filter::can_calculate_in_place(){
    return true;
  }



}
