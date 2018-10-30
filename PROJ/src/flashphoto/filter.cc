#include "flashphoto/tool.h"
#include <assert.h>
#include <algorithm>
#include <cmath>
#include "flashphoto/color_data.h"
#include "flashphoto/pixel_buffer.h"

namespace image_filters {

  Filter::Filter() : buffer_(NULL) {
  }

  Filter::~Filter() {}

  void Filter::ApplyToBuffer(PixelBuffer *buffer) {

    if (!can_calculate_in_place()){
      PixelBuffer temp = PixelBuffer(buffer);
      SetupFilter();
      for(int i=0; i<buffer->height; i++){
        for(int j=0; j<buffer->width; j++){
          CalculateFilteredPixel(buffer, i, j);
        }
      }
      CleanupFilter();
    }
    else{
      SetupFilter();
      for(int i=0; i<buffer->height; i++){
        for(int j=0; j<buffer->width; j++){
          CalculateFilteredPixel(buffer, i, j);
        }
      }
      CleanupFilter();
    }
    
  }

  bool can_calculate_in_place(){
    return true;
  }



}
