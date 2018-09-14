
#include <iostream>
#include "point2.h"
#include <math.h> //FOR SQRT()

using std::cout;
using std::endl;

Point2::p00(){
  x = 0.0;
  y = 0.0;
}

Point2::p11(float NewX, float NewY){
  if (NewX == 1.0 && NewY == 1.0){
    x = NewX;
    y = NewY;
  }
}

Point2::p21(float NewX, float NewY){
  if (NewX == 2.0 && NewY == 1.0){
    x = NewX;
    y = NewY;
  }
}

Point2::p12(float NewX, float NewY){
  if (NewX == 1.0 && NewY == 2.0){
    x = NewX;
    y = NewY;
  }
}

Point2::pPI45(float NewX, float NewY){
  if (NewX == sqrt(2)/2 && NewY == sqrt(2)/2){
    x = NewX;
    y = NewY;
  }
}

Point2::p_a(float NewX, float NewY){
  if (NewX == 3.0 && NewY == 5.0){
    x = NewX;
    y = NewY;
  }
}

Point2::p_b(float NewX, float NewY){
  if (NewX == 4.0 && NewY == 4.0){
    x = NewX;
    y = NewY;
  }
}

DistanceBetween(Point2::Point2 NewPtr){
  distance = sqrt( pow( (x-NewPtr.x), 2) + pow( (y-NewPtr.y), 2) );
  return distance;
}

